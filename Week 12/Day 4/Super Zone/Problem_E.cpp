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
const ll INF = 1e9 + 1;
void solve()
{
    ll i, n, c = 0;
    cin >> n;
    vl v1(n);
    map<ll, ll> m1;
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        m1[v1[i]]++;
    }
    v1.clear();
    for (auto it : m1)
        v1.push_back(it.second);
    sort(v1.begin(), v1.end());
    ll m = n;
    n = v1.size();
    // cout << n << endl;
    i = 0;
    while (1)
    {
        if (i == n - 1)
        {
            if (v1[i] > c)
                cout << v1[i] - c << endl;
            else if (m % 2)
                cout << 1 << endl;
            else
                cout << 0 << endl;
            return;
        }
        else
            c += v1[i];
        i++;
    }
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