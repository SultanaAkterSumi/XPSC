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
typedef vector<ll> vl;
const ll N = 1e5 + 1;
const ll MOD = 998244353;

void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    sort(v1.begin(), v1.end());
    ll l = 0, r = v1[n - 1] - v1[0], mid, res = v1[n - 1] - v1[0];
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll x = 0, y = 1e9;
        ll c = 1;
        for (i = 0; i < n; i++)
        {
            ll x1 = max(0LL, v1[i] - mid);
            ll y1 = min(1000000000LL, v1[i] + mid);
            if (y1 < x || x1 > y)
            {
                c++;
                x = x1;
                y = y1;
            }
            else
            {
                x = max(x, x1);
                y = min(y, y1);
            }
            if (c > 3)
                break;
        }
        if (c > 3)
            l = mid + 1;
        else
        {
            r = mid - 1;
            res = mid;
        }
    }
    cout << res << endl;
}

int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}
