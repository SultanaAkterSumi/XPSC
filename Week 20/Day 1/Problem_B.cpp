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
const ll N = 2e5 + 9;
void solve()
{
    ll n, i, x, y, ans = 0;
    cin >> n;
    vector<pair<ll, ll>> v1;
    for (i = 0; i < n; i++)
    {
        cin >> x >> y;
        v1.push_back({x, y});
    }
    sort(v1.begin(), v1.end());
    for (i = 0; i < n; i++)
    {
        // cout << v1[i].first << ' ' << v1[i].second << endl;
        if (i + 1 < n && v1[i].first == v1[i + 1].first)
            ans += (n - 2);
        ll j = i - 1, k = i + 1;
        while (j >= 0 && v1[j].first == v1[i].first)
            j--;
        if (j >= 0 && v1[j].second == v1[i].second)
            j--;
        while (k < n && v1[k].first == v1[i].first)
            k++;
        if (k < n && v1[k].second == v1[i].second)
            k++;
        if (j >= 0 && k < n && v1[j].first + 1 == v1[i].first && v1[k].first - 1 == v1[i].first)
            ans++;
        // cout << ans << endl;
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