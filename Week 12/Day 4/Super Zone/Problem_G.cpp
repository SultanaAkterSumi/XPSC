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
    ll n, k, i;
    string s1;
    cin >> n >> k >> s1;
    vector<ll> v1(26), v2(26);
    for (auto it : s1)
    {
        v1[it - 'a']++;
    }
    i = 0;
    while (k)
    {
        if (v1[i] >= k)
        {
            v2[i] = k;
            k = 0;
        }
        else
        {
            k -= v1[i];
            v2[i] = v1[i];
        }
        i++;
    }
    for (i = 0; i < n; i++)
    {
        if (v2[s1[i] - 'a'] == 0)
            cout << s1[i];
        else
            v2[s1[i] - 'a']--;
    }
    cout << endl;
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