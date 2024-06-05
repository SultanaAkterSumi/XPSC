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

void solve()
{
    ll n;
    cin >> n;
    vl ans;
    ans.push_back(1);
    while (2 * ans.back() <= n)
    {
        ans.push_back(2 * ans.back());
    }
    while (ans.back() != n)
    {
        ll temp = 1, res = 1;
        while (temp + ans.back() <= n)
        {
            if ((temp + ans.back()) % temp == 0)
                res = temp;
            temp = temp << 1;
        }
        ans.push_back(ans.back() + res);
    }
    n = ans.size();
    cout << n << endl;
    while (n--)
    {
        cout << ans[n] << ' ';
    }
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