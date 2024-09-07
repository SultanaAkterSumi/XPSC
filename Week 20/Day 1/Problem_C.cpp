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
const ll N = 1e18;
void solve()
{
    ll n, k;
    cin >> n >> k;
    ll m = n + k - 1;
    ll l = k, r = m, mid, res = N;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll t1 = ((mid * (mid + 1)) / 2);
        ll t2 = t1 - (((k - 1) * k) / 2);
        ll t = t2 - ((m * (m + 1)) / 2) + t1;
        // cout << mid << ' ' << t << endl;
        res = min(res, abs(t));
        if (t < 0)
            l = mid + 1;
        else if (t > 0)
            r = mid - 1;
        else
            break;
    }
    cout << res << endl;
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