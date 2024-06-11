#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set1 = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set2 = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll INF = 1e9 + 1;
void solve()
{
    ll n, m, i, j, num;
    cin >> n >> m;
    vector<multiset<ll>> v1;
    vector<pair<ll, ll>> v2;
    for (i = 0; i < n; i++)
    {
        multiset<ll> ms1;
        for (j = 0; j < m; j++)
        {
            cin >> num;
            ms1.insert(num);
            v2.push_back({num, i});
        }
        v1.push_back(ms1);
    }
    sort(v2.begin(), v2.end());
    vector<vl> ans(n, vl(m, 0));
    ll player = 0;
    for (i = 0; i < m; i++, player++)
    {
        ans[v2[i].second][player] = v2[i].first;
        v1[v2[i].second].erase(v1[v2[i].second].find(v2[i].first));
    }
    for (i = 0; i < n; i++)
    {

        for (j = 0; j < m; j++)
        {
            if (ans[i][j] == 0)
            {
                ans[i][j] = (*v1[i].begin());
                v1[i].erase(v1[i].begin());
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
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