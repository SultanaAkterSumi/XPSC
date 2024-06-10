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
    ll n, i, ans = 0, c = 0, index;
    cin >> n;
    vl v1(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v1[i];
    for (i = n; i >= 1; i--)
    {
        if (i % 2)
        {
            if (v1[i] >= 0)
            {
                ans += (c + v1[i]);
                c = 0;
            }
        }
        else
        {

            if (v1[i] > 0)
            {
                if (c == 0)
                    index = i;
                c += v1[i];
            }
        }
    }
    if (c)
    {
        ll Max = 0;
        for (i = 1; i <= index; i++)
        {
            if (i % 2)
            {
                Max = max(Max, c + v1[i]);
            }
            else
            {
                if (v1[i] > 0)
                    c -= v1[i];
                Max = max(Max, c);
            }
        }
        ans += Max;
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