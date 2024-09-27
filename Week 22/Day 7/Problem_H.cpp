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
const ll N = 1e6 + 1;

void solve()
{
    ll n, i, j;
    cin >> n;
    string s1;
    vector<string> v1;
    vector<set<ll>> ans(n);
    for (i = 0; i < n; i++)
    {
        cin >> s1;
        v1.push_back(s1);
        ans[i].insert(i + 1);
    }
    for (i = n - 1; i >= 0; i--)
        for (j = 0; j < n; j++)
            if (v1[j][i] == '1')
                for (auto it : ans[j])
                    ans[i].insert(it);
    for (auto it : ans)
    {
        cout << it.size() << ' ';
        for (auto it1 : it)
            cout << it1 << ' ';
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