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
    ll n, l, r, i, j, sum, ans;
    cin >> n >> l >> r;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    i = 0, j = 0, sum = 0, ans = 0;
    while (i < n && j < n)
    {
        while (sum < l && j < n)
        {
            sum += v1[j];
            j++;
        }
        while (sum > r && i < j)
        {
            sum -= v1[i];
            i++;
        }
        if (sum >= l && sum <= r)
        {
            ans++, i = j, sum = 0;
        }
    }
    cout << ans << endl;
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