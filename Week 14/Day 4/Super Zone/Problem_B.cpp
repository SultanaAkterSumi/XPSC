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
const ll N = 1e6 + 1;

void solve()
{
    ll x, y, k;
    cin >> x >> y >> k;
    ll t1 = y - (x % y);
    if (k >= t1)
    {
        k -= t1;
        x += t1;
        while (x % y == 0)
            x /= y;
    }
    else
    {
        x += k;
        k = 0;
    }
    while (k)
    {
        if (x == 1)
        {
            t1 = y - 1;
            x += (k % t1);
            k = 0;
        }
        else
        {
            t1 = y - (x % y);
            if (k >= t1)
            {
                k -= t1;
                x += t1;
                while (x % y == 0)
                    x /= y;
            }
            else
            {
                x += k;
                k = 0;
            }
        }
    }
    cout << x << endl;
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