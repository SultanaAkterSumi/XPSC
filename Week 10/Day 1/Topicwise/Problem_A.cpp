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
    ll n1, n2, i, ans = 0, num;
    cin >> n1 >> n2;
    vl v1(n1), v2(n2);
    for (i = 0; i < n1; i++)
        cin >> v1[i];
    for (i = 0; i < n2; i++)
        cin >> v2[i];
    sort(v1.begin(), v1.end());
    for (i = 0; i < n2; i++)
    {
        cout << upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << ' ';
    }
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