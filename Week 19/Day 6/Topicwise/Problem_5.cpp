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
vl a(N, 1), t(4 * N), lazy(4 * N, 1);
void build(ll m, ll b, ll e)
{
    if (b == e)
    {
        t[m] = a[b];
        return;
    }
    ll mid = (b + e) / 2;
    build(2 * m, b, mid);
    build(2 * m + 1, mid + 1, e);
    t[m] = t[2 * m] + t[2 * m + 1];
}
void propagate(ll m, ll b, ll e)
{
    t[m] *= lazy[m];
    t[m] %= MOD;
    if (b != e)
    {
        lazy[2 * m] *= lazy[m], lazy[2 * m + 1] *= lazy[m];
        lazy[2 * m] %= MOD, lazy[2 * m + 1] %= MOD;
    }
    lazy[m] = 1;
}
void update(ll m, ll b, ll e, ll l, ll r, ll v)
{
    propagate(m, b, e);
    if (r < b || l > e)
        return;
    if (b == l && e == r)
    {
        lazy[m] *= v;
        lazy[m] %= MOD;
        propagate(m, b, e);
        return;
    }
    ll mid = (b + e) / 2;
    update(2 * m, b, mid, l, min(mid, r), v);
    update(2 * m + 1, mid + 1, e, max(l, mid + 1), r, v);
    t[m] = (t[2 * m] + t[2 * m + 1]) % MOD;
}
ll query(ll m, ll b, ll e, ll l, ll r)
{
    propagate(m, b, e);
    if (r < b || l > e)
        return 0;
    if (l == b && r == e)
        return t[m];
    ll mid = (b + e) / 2;
    return (query(2 * m, b, mid, l, min(mid, r)) + query(2 * m + 1, mid + 1, e, max(l, mid + 1), r)) % MOD;
}
int main()
{
    op()
        ll n,
        m, num, l, r, v;
    cin >> n >> m;
    build(1, 1, n);
    while (m--)
    {
        cin >> num;
        if (num == 1)
        {
            cin >> l >> r >> v;
            l++;
            update(1, 1, n, l, r, v);
        }
        else
        {
            cin >> l >> r;
            l++;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
}