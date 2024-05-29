#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    ll n, k, i;
    cin >> n >> k;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    ordered_set os1;
    for (i = 0; i < k; i++)
    {
        os1.insert(v1[i]);
    }
    ll pos = k / 2;
    if (k % 2 == 0)
        pos--;
    cout << *os1.find_by_order(pos) << ' ';
    i = 0;
    ll j = k;
    while (j < n)
    {

        auto it = os1.lower_bound(v1[i] - 1);

        os1.erase(it);
        os1.insert(v1[j]);

        cout << *os1.find_by_order(pos) << ' ';
        i++;
        j++;
    }
    cout << endl;
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}