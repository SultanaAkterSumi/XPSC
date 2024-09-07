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
const ll N = 2e5 + 1;
ll n;
string s1;
vl v1(N), ans(N);
vector<bool> vis(N);
void fun(vl &t1, ll i, ll &t2)
{
    if (vis[i])
        return;
    vis[i] = true, t1.push_back(i);
    if (s1[v1[i] - 1] == '0')
        t2++;
    fun(t1, v1[i], t2);
}
void solve()
{
    ll i;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> v1[i];
        ans[i] = 0, vis[i] = false;
    }
    cin >> s1;
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
        {

            vl t1;
            ll t2 = 0;
            fun(t1, i, t2);

            for (auto it : t1)
            {

                ans[it] = t2;
            }
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