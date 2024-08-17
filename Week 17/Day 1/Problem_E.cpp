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
    ll n, k, i;
    cin >> n >> k;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    bool f1 = true;
    if (v1[0] == v1[n - 1])
    {
        ll c = 0;
        for (i = 0; i < n; i++)
        {
            if (v1[i] == v1[0])
                c++;
        }
        if (c < k)
            f1 = false;
    }
    else
    {
        ll c1 = 0, c2 = 0, i1, i2;
        for (i = 0; i < n; i++)
        {
            if (v1[i] == v1[0] && c1 < k)
            {
                c1++;
                i1 = i;
            }
        }
        for (i = n - 1; i >= 0; i--)
        {
            if (v1[i] == v1[n - 1] && c2 < k)
            {
                c2++;
                i2 = i;
            }
        }
        if (c1 < k || c2 < k || i1 > i2)
            f1 = false;
    }
    if (f1)
        yes else no
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