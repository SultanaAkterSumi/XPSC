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

    t[m] = t[2 * m] & t[2 * m + 1];
}

ll AND(ll m, ll l, ll r, ll i, ll j)
{
    if (j < l || r < i)
        return (1 << 31) - 1;
    if (l == i && r == j)
        return t[m];
    ll mid = (l + r) / 2;
    return AND(2 * m, l, mid, i, min(mid, j)) & AND(2 * m + 1, mid + 1, r, max(mid + 1, i), j);
}
void solve()
{
    ll n, i, q, x;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    cin >> q;
    while (q--)
    {
        ll l, k;
        cin >> l >> k;
        ll left = l, right = n, mid, res = -1;

        while (left <= right)
        {
            mid = (left + right) / 2;
            ll ans = AND(1, 1, n, l, mid);

            bool f = false;

            if (k <= ans)
                f = true;
            if (f)
            {
                res = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        cout << res << ' ';
    }
    cout << endl;
}
int main()
{
    op()
        ll t;
    cin >> t;
    while (t--)
        solve();
}