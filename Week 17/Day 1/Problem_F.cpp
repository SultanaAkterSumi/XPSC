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
    ll n;
    cin >> n;
    ll i, j;
    vl v1(n);
    v1[n / 2] = 1;
    for (i = 2; i <= n && i <= 3; i++)
    {
        if (i == 2)
            v1[0] = 2;
        else
            v1[n - 1] = 3;
    }
    j = 4;
    for (i = 1; i < n / 2; i++)
    {
        v1[i] = j;
        j++;
    }
    for (i = n / 2 + 1; i < n - 1; i++)
    {
        v1[i] = j;
        j++;
    }
    for (auto it : v1)
        cout << it << ' ';
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