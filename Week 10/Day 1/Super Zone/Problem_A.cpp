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
const ll N = 2e5 + 1;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll num = 1, c = 0;
    while (1)
    {

        ll l = 1, r = n, mid, res = -1;
        if (r % 2 == 0)
            r--;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (mid % 2 == 0)
                mid--;
            if (mid * num > n)
            {
                r = mid - 2;
            }
            else
            {
                res = mid;
                l = mid + 2;
            }
        }
        if (((res + 1) / 2) + c >= k)
            break;
        else
            c += ((res + 1) / 2);
        num = num << 1;
    }
    // cout << c << endl;
    k -= c;
    cout << (2 * k - 1) * num << endl;
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