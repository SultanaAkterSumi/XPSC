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

void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    ll l = v1[0] + v1[1], r = v1[n - 2] + v1[n - 1], ans = 1;
    for (i = l; i <= r; i++)
    {
        ll p = 0, q = n - 1, c = 0;
        while (p < q)
        {
            if (v1[p] + v1[q] == i)
            {
                p++;
                q--;
                c++;
            }
            else if (v1[p] + v1[q] > i)
                q--;
            else
                p++;
        }
        ans = max(ans, c);
    }
    cout << ans << endl;
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