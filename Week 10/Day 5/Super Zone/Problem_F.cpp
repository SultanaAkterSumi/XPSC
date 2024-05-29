#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
typedef pair<ll, ll> pll;
const ll N = 2e5 + 1;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    map<pair<ll, pair<ll, ll>>, ll> m1;
    map<pair<ll, ll>, ll> m2;
    map<pair<ll, ll>, ll> m3;
    map<pair<ll, ll>, ll> m4;
    for (i = 2; i < n; i++)
    {
        m1[{v1[i - 2], {v1[i - 1], v1[i]}}]++;
        m2[{v1[i - 2], v1[i - 1]}]++;
        m3[{v1[i - 2], v1[i]}]++;
        m4[{v1[i - 1], v1[i]}]++;
    }
    ll ans = 0;
    for (i = 2; i < n; i++)
    {
        ans += (m2[{v1[i - 2], v1[i - 1]}] + m3[{v1[i - 2], v1[i]}] + m4[{v1[i - 1], v1[i]}] - 3 * m1[{v1[i - 2], {v1[i - 1], v1[i]}}]);
        // cout << ans << endl;
    }
    cout << ans / 2 << endl;
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