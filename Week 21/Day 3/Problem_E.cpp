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
    ll n, k, m, i, j, x, ans = 0;
    string s1;
    cin >> n >> k >> s1;
    m = k;
    if (k % 2)
        m--;
    m /= 2;
    for (i = 0, j = n - 1; i < m; i++, j--)
    {
        vl v1(26);
        ll cnt = 0, Max = 0;
        for (x = i; x < n; x += k)
        {
            v1[s1[x] - 'a']++;
            cnt++;
        }
        for (x = j; x >= 0; x -= k)
        {
            v1[s1[x] - 'a']++;
            cnt++;
        }
        for (x = 0; x < 26; x++)
            Max = max(Max, v1[x]);
        ans += (cnt - Max);
    }
    if (k % 2)
    {
        vl v1(26);
        ll cnt = 0, Max = 0;
        for (x = i; x < n; x += k)
        {
            v1[s1[x] - 'a']++;
            cnt++;
        }
        for (x = 0; x < 26; x++)
            Max = max(Max, v1[x]);
        ans += (cnt - Max);
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