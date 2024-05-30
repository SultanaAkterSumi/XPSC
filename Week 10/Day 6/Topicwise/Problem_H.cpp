#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
    ll n, i, cost = 0;
    string s1, s2;
    cin >> n >> s1;
    vector<set<ll>> v1(26);
    vl v2(n);
    for (i = 0; i < n; i++)
    {
        v1[s1[i] - 'a'].insert(i);
    }
    s2 = s1;
    reverse(s2.begin(), s2.end());

    for (i = 0; i < n; i++)
    {
        v2[i] = *v1[s2[i] - 'a'].begin();
        v1[s2[i] - 'a'].erase(v1[s2[i] - 'a'].begin());
    }
    ordered_set<ll> os1;
    for (i = 0; i < n; i++)
    {
        cost += os1.order_of_key(v2[i]);
        os1.insert(v2[i]);
    }
    cout << cost << endl;
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