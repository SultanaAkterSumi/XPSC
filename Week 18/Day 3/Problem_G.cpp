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
    ll n, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll c1 = 0, r = n - 1, c2 = 0, ans = 0;
    while (r >= 0)
    {
        while (r >= 0 && v1[r] == v1[n - 1])
        {
            c1++;
            r--;
        }
        while (r >= 0 && v1[r] != v1[n - 1])
        {
            c2++;
            r--;
        }
        while (c2)
        {
            if (c1 <= c2)
            {
                ans++;
                c2 -= c1;
                c1 = c1 << 1;
            }
            else
            {
                ans++;
                r -= (c1 - c2);
                c1 = c1 << 1;
                c2 = 0;
                break;
            }
        }
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