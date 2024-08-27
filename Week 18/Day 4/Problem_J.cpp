#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set1 = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set2 = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll N = 1e10;
bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.first.first != b.first.first)
        return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}
void solve()
{
    ll n, i;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> v1;
    for (i = 1; i <= n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v1.push_back({{a, b}, i});
    }
    sort(v1.begin(), v1.end(), cmp);
    for (i = 1; i < n; i++)
    {
        if (v1[i - 1].first.first == v1[i].first.first)
        {
            cout << v1[i - 1].second << ' ' << v1[i].second << endl;
            return;
        }
        else if (v1[i - 1].first.second >= v1[i].first.second)
        {
            cout << v1[i].second << ' ' << v1[i - 1].second << endl;
            return;
        }
    }
    cout << -1 << ' ' << -1 << endl;
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