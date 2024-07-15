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
const ll N = 1e5 + 1;
ll fun(ll n)
{
    ll low = 2, high = 10000000000, mid, res = 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        ll temp = mid * (mid - 1) / 2;
        if (temp == n)
            return mid;
        if (temp < n)
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}
void solve()
{
    ll n;
    cin >> n;
    ll res = fun(n);
    ll temp = res * (res - 1) / 2;
    temp = n - temp;
    res += temp;
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