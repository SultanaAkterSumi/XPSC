#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define gcd(a, b) __gcd(a, b)
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, k, q, i, j, x, ans = 0, days = 0;
    cin >> n >> k >> q;

    for (i = 0, j = 0; i < n; i++)
    {
        cin >> x;
        if (x <= q)
            days++;
        else
        {
            if (days >= k)
            {
                ll temp = days + 1 - k;
                ans += ((temp + 1) * temp) / 2;
            }
            days = 0;
        }
    }

    if (days >= k)
    {
        ll temp = days + 1 - k;
        ans += ((temp + 1) * temp) / 2;
    }
    cout << ans << endl;
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}