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
    ll n, m, k, comm = 0, num, i, a = 0, b = 0;
    cin >> n >> m >> k;
    vector<bool> v1(k + 1, 0), v2(k + 1, 0);
    for (i = 0; i < n; i++)
    {
        cin >> num;
        if (num <= k && !v1[num])
        {
            v1[num] = true;
            a++;
        }
    }
    for (i = 0; i < m; i++)
    {
        cin >> num;
        if (num <= k && !v2[num])
        {
            v2[num] = true;
            b++;
            if (v1[num])
                comm++;
        }
    }
    ll t1 = k / 2;
    if (a >= t1 && b >= t1)
    {
        if (a - comm + b - comm + comm >= k)
            yes else no
    }
    else
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