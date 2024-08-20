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

ll SUM(ll m, ll l, ll r, ll i, ll j)
{
    if (j < l || r < i)
        return 0;
    if (l == i && r == j)
        return t[m];
    ll mid = (l + r) / 2;
    return SUM(2 * m, l, mid, i, min(mid, j)) + SUM(2 * m + 1, mid + 1, r, max(mid + 1, i), j);
}
void solve()
{
    ll n, m, i, q, x;
    cin >> n >> m;
    vector<pair<ll, ll>> v1;

    for (i = 0; i < m; i++)
    {
        ll l, r;
        cin >> l >> r;
        v1.push_back({l, r});
    }
    cin >> q;
    vl v2(q + 1);
    for (i = 1; i <= q; i++)
        cin >> v2[i];
    ll l = 1, r = q, mid, res = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        for (i = 1; i <= n; i++)
            a[i] = 0;
        for (i = 1; i <= mid; i++)
            a[v2[i]] = 1;
        build(1, 1, n);
        bool f = false;
        for (i = 0; i < m && !f; i++)
        {
            ll ans = SUM(1, 1, n, v1[i].first, v1[i].second);
            if (v1[i].second - v1[i].first + 1 - ans < ans)
                f = true;
        }
        if (f)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res << endl;
}
int main()
{
    op()
        ll t;
    cin >> t;
    while (t--)
        solve();
}