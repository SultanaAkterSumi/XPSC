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
    ll n, x, y;
    cin >> n >> x >> y;
    if (x > y)
        swap(x, y);
    n -= 1;
    // cout << n << endl;
    ll l = 0, r = 1e9, mid, res;
    while (l <= r)
    {

        mid = (l + r) / 2;
        // cout << l << ' ' << r << ' ' << mid << endl;
        if (((mid / x) + (mid / y)) >= n)
        {
            r = mid - 1;
            res = mid;
            // cout << res << endl;
        }
        else
            l = mid + 1;
    }
    cout << x + res << endl;
}

int main()
{
    op()

        int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}
