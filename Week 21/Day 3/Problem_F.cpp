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
#define yes cout << "Yes\n";
#define no cout << "No\n";
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
const ll N = 1e3 + 1;
void solve()
{
    ll n, i, num, j;
    cin >> n;
    vector<vl> v1(n + 1);
    for (i = 1; i <= n; i++)
    {
        v1[i].push_back(0);
    }
    for (i = 1; i <= n; i++)
    {
        cin >> num;
        v1[num].push_back(i);
    }
    for (i = 1; i <= n; i++)
    {
        v1[i].push_back(n + 1);
    }
    vl ans(n + 1, -1);
    for (i = 1; i <= n; i++)
    {
        ll temp = 0, m = v1[i].size();
        for (j = 1; j < m; j++)
        {
            temp = max(temp, v1[i][j] - v1[i][j - 1]);
        }
        for (j = temp; j <= n && ans[j] == -1; j++)
        {
            ans[j] = i;
        }
    }
    for (i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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