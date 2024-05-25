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
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}
void solve()
{
    ll n, i;
    cin >> n;
    vector<pll> v1;
    ordered_set os1;
    for (i = 0; i < n; i++)
    {
        pll p1;
        cin >> p1.first >> p1.second;
        v1.push_back(p1);
        os1.insert(p1.second);
    }
    sort(v1.begin(), v1.end(), cmp);
    ll ans = 0;
    for (i = 0; i < n - 1; i++)
    {
        ans += os1.order_of_key(v1[i].second);
        os1.erase(v1[i].second);
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