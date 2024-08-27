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

void solve()
{
    string s, t;
    cin >> s >> t;
    ll n = s.size(), m = t.size(), i, j;
    for (i = 0; i < m; i++)
    {

        for (j = 0; j < n; j++)
        {
            bool f = false;
            if (n - j >= i + 1)
            {
                ll a, b;
                for (a = 0, b = j; a <= i; a++, b++)
                {
                    if (t[a] != s[b])
                        break;
                }
                if (a > i)
                    f = true;
            }
            if (f && (m - i - 1) <= (j + i))
            {
                ll a, b;
                for (a = i + 1, b = i + j - 1; a < m; a++, b--)
                {
                    if (t[a] != s[b])
                        break;
                }
                if (a == m)
                {
                    yes return;
                }
            }
        }
    }
    no
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