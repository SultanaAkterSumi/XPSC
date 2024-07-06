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

ll Binary_Search(ll n, ll x)
{
    ll low = 0, high = INT_MAX, mid, res = 0, t1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid >= n)
        {
            high = mid - 1;
        }
        else
        {
            t1 = n - mid;
            t1 = (t1 * (t1 + 1)) / 2;
            t1 -= mid;
            if (t1 == x)
            {
                return mid;
            }
            else if (t1 < x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }

    return res;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    cout << Binary_Search(n, k);
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}