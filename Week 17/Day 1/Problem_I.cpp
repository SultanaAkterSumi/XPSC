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
const ll N = 5e5 + 1;

void solve()
{
    ll n, i, ans = 0, c = 0;
    cin >> n;
    vl v1(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v1[i];
    map<ll, ll> m1, m2;
    for (i = n; i > 0; i--)
    {
        if (!m1.count(v1[i]))
        {
            m1[v1[i]] = i;
        }
        else
        {
            ans += (n - m1[v1[i]]);
            m1[v1[i]] = i;
        }
    }
    for (i = n; i > 0; i--)
    {
        if (m1[v1[i]] == i)
        {
            ans += c;
        }

        if (m2.count(v1[i]))
            c++;
        m2[v1[i]]++;
    }
    for (auto it : m2)
    {
        if (it.second > 1)
            ans += it.second;
    }
    cout << ((n * (n + 1)) / 2) - ans << endl;
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