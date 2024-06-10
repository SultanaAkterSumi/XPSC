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
    ll n, m, i, k;
    cin >> n >> m >> k;
    vl v1(n), opr(m), temp(n);
    vector<pair<pair<ll, ll>, ll>> v3;
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < m; i++)
    {
        pair<pair<ll, ll>, ll> p1;
        cin >> p1.first.first >> p1.first.second >> p1.second;
        v3.push_back(p1);
    }
    for (i = 0; i < k; i++)
    {
        ll l, r, j;
        cin >> l >> r;
        opr[l - 1]++;
        if (r < m)
            opr[r]--;
    }
    for (i = 0; i < m; i++)
    {
        if (i)
            opr[i] += opr[i - 1];
        ll a = v3[i].first.first, b = v3[i].first.second, c = v3[i].second;
        temp[a - 1] += (opr[i] * c);
        if (b < n)
            temp[b] -= (opr[i] * c);
    }
    for (i = 1; i < n; i++)
        temp[i] += temp[i - 1];
    for (i = 0; i < n; i++)
        cout << v1[i] + temp[i] << ' ';
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