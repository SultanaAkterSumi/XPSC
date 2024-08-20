#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 9;
vl a(N), t(4 * N);
void build(ll m, ll l, ll r)
{
    if (l == r)
    {
        t[m] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * m, l, mid);
    build(2 * m + 1, mid + 1, r);
    t[m] = t[2 * m] + t[2 * m + 1];
}
void update(ll m, ll l, ll r, ll i, ll v)
{
    if (i < l || i > r)
        return;
    if (l == r)
    {
        t[m] = v;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * m, l, mid, i, v);
    update(2 * m + 1, mid + 1, r, i, v);
    t[m] = t[2 * m] + t[2 * m + 1];
}
ll SUM(ll m, ll l, ll r, ll i, ll j)
{
    if (j < l || r < i)
        return 0;
    if (l == i && r == j)
        return t[m];
    ll mid = (l + r) / 2;
    return SUM(2 * m, l, mid, i, min(mid, j)) + SUM(2 * m + 1, mid + 1, r, max(mid + 1, i), j);
}
int main()
{
    op()
        ll n,
        q, i, num, v, l, r;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        cin >> num;
        if (num == 1)
        {
            cin >> i >> v;
            i++;
            update(1, 1, n, i, v);
        }
        else
        {
            cin >> l >> r;
            l++;
            r++;
            cout << SUM(1, 1, n, l, r - 1) << endl;
        }
    }
}