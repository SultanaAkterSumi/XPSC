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
const ll N = 131080;
vl a(N), t(4 * N);
void build(ll m, ll l, ll r)
{
    if (l == r)
    {
        t[m] = a[l];
        return;
    }
    ll c = -1, temp = r - l + 1;
    while (temp)
    {
        c++;
        temp = temp >> 1;
    }
    ll mid = (l + r) / 2;
    build(2 * m, l, mid);
    build(2 * m + 1, mid + 1, r);
    if (c % 2)
        t[m] = t[2 * m] | t[2 * m + 1];
    else
        t[m] = t[2 * m] ^ t[2 * m + 1];
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
    ll c = -1, temp = r - l + 1;
    while (temp)
    {
        c++;
        temp = temp >> 1;
    }
    ll mid = (l + r) / 2;
    update(2 * m, l, mid, i, v);
    update(2 * m + 1, mid + 1, r, i, v);
    if (c % 2)
        t[m] = t[2 * m] | t[2 * m + 1];
    else
        t[m] = t[2 * m] ^ t[2 * m + 1];
}

int main()
{
    op()
        ll n,
        q, i, m, v;
    cin >> n >> q;
    m = 1 << n;
    for (i = 1; i <= m; i++)
        cin >> a[i];
    build(1, 1, m);
    while (q--)
    {
        cin >> i >> v;
        update(1, 1, m, i, v);
        cout << t[1] << endl;
    }
}