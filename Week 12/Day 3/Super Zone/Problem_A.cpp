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
void solve()
{
    ll n, m, i, j, num;
    cin >> n;
    set<ll> s1;
    vector<set<ll>> v1;
    map<ll, vl> m1;
    for (i = 0; i < n; i++)
    {
        cin >> m;
        set<ll> s2;
        for (j = 0; j < m; j++)
        {
            cin >> num;
            s1.insert(num);
            s2.insert(num);
            m1[num].push_back(i);
        }
        v1.push_back(s2);
    }
    ll ans = 0;
    for (auto it1 : m1)
    {
        set<ll> s3;
        for (i = 0; i < n; i++)
        {
            if (find(it1.second.begin(), it1.second.end(), i) != it1.second.end())
                continue;
            s3.insert(v1[i].begin(), v1[i].end());
        }
        if (s1 != s3 && ans < s3.size())
            ans = s3.size();
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