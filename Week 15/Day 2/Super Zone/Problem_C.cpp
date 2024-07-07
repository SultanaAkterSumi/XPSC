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
    ll n, i, j, x;
    cin >> n >> x;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    vl v2(n + 1); // subarray length 0 to n
    for (i = 0; i <= n; i++)
    {
        ll ans, sum = 0;
        for (j = 0; j < i; j++)
            sum += v1[j];
        ans = sum;
        ll k = 0;
        while (j < n)
        {
            sum = sum - v1[k] + v1[j];
            ans = max(ans, sum);
            j++;
            k++;
        }
        // cout << ans << endl;
        v2[i] = ans;
    }
    // for (i = 0; i <= n; i++)
    //     cout << v2[i] << endl;
    for (i = 0; i <= n; i++)
    { // add x to the elements on i distinct positions
        ll ans = 0;
        for (j = 0; j <= n; j++)
        {
            ans = max(ans, v2[j] + (x * min(j, i)));
        }
        cout << ans << ' ';
    }
    cout << endl;
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