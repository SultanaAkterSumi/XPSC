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
const ll MAX = 1e9 + 7;
const ll N = 2e5 + 9;
vl a(N);
vector<bool> t(4 * N);
void build(ll m, ll l, ll r)
{
    if (l == r)
    {
        if (a[l] / 10)
            t[m] = true;
        else
            t[m] = false;
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * m, l, mid);
    build(2 * m + 1, mid + 1, r);

    t[m] = t[2 * m] || t[2 * m + 1];
}

void update(ll m, ll l, ll r, ll i, ll j)
{
    if (j < l || r < i || !t[m])
        return;
    if (l == r && i == j)
    {
        ll t1 = 0;
        while (a[i])
        {
            t1 += (a[i] % 10);
            a[i] /= 10;
        }
        a[i] = t1;

        if (a[i] / 10)
            t[m] = true;
        else
            t[m] = false;
        return;
    }
    ll mid = (l + r) / 2;
    update(2 * m, l, mid, i, min(mid, j));
    update(2 * m + 1, mid + 1, r, max(mid + 1, i), j);
    t[m] = t[2 * m] || t[2 * m + 1];
}
void solve()
{
    ll n, i, q, x, num, l, r;
    cin >> n >> q;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);

    while (q--)
    {
        cin >> num;
        if (num == 1)
        {
            cin >> l >> r;
            update(1, 1, n, l, r);
        }
        else
        {
            cin >> x;
            cout << a[x] << '\n';
        }
    }
}
int main()
{
    op()
        ll t;
    cin >> t;
    while (t--)
        solve();
}