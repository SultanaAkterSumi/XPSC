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
const ll N = 2e5 + 1;
void solve()
{
    ll n, m, u, v, i;
    cin >> n >> m;
    vector<vl> v1(n + 1);
    while (m--)
    {
        cin >> u >> v;
        v1[u].push_back(v);
        v1[v].push_back(u);
    }
    map<ll, ll> m1;
    for (i = 1; i <= n; i++)
    {
        if (v1[i].size())
            m1[v1[i].size()]++;
    }

    if (m1.size() == 2)
    {
        auto it = m1.begin();
        ll a1 = it->first, b1 = it->second;
        ++it;
        ll a2 = it->first, b2 = it->second;
        cout << a2 << ' ' << a2 - 1 << endl;
    }
    else
    {
        auto it = m1.begin();
        ll a1 = it->first, b1 = it->second;
        ++it;
        ll a2 = it->first, b2 = it->second;
        ++it;
        ll a3 = it->first, b3 = it->second;
        if (b2 == 1)
        {
            swap(a2, a3);
            swap(b2, b3);
        }
        cout << b2 << ' ' << a2 - 1 << endl;
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