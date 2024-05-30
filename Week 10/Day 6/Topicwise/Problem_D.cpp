#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    ordered_set<ll> os1;
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (i = 0; i < k; i++)
        os1.insert(v1[i]);
    ll pos = k / 2;
    if (k % 2 == 0)
        pos--;
    ll cost = 0;
    ll mid = *os1.find_by_order(pos);
    for (auto it : os1)
        cost += abs(mid - it);
    cout << cost << ' ';
    i = 0;
    ll j = k;
    if (k % 2)
    {
        while (j < n)
        {
            cost -= abs(v1[i] - *os1.find_by_order(pos));
            os1.erase(os1.lower_bound(v1[i] - 1));
            os1.insert(v1[j]);
            cost += abs(v1[j] - *os1.find_by_order(pos));
            cout << cost << ' ';
            i++;
            j++;
        }
    }
    else
    {
        while (j < n)
        {
            cost -= abs(v1[i] - *os1.find_by_order(pos));
            ll prev = *os1.find_by_order(pos);
            os1.erase(os1.lower_bound(v1[i] - 1));
            os1.insert(v1[j]);
            cost += abs(v1[j] - *os1.find_by_order(pos));
            cost -= (*os1.find_by_order(pos) - prev);
            cout << cost << ' ';
            i++;
            j++;
        }
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