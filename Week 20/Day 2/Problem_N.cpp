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
const ll N = 1e18;
void solve()
{
    ll n, m, k, sum = 0, i;
    cin >> n >> m >> k;
    vl v1(n), v2(m);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        sum += v1[i];
    }
    for (i = 0; i < m; i++)
        cin >> v2[i];
    sort(v2.rbegin(), v2.rend());
    sort(v1.begin(), v1.end());
    if (k % 2)
    {
        sum -= v1[0];
        sum += max(v1[0], v2[0]);
    }
    else
    {
        sum -= v1[0];
        if (v1[0] < v2[0])
        {
            sum += v2[0];
            swap(v1[0], v2[0]);
            sort(v2.rbegin(), v2.rend());
            sort(v1.begin(), v1.end());
        }
        else
            sum += v1[0];

        if (v1[n - 1] > v2[m - 1])
        {
            sum -= v1[n - 1];
            sum += v2[m - 1];
        }
    }
    cout << sum << endl;
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