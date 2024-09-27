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
const ll N = 1e6 + 1;

void solve()
{
    ll n, d, k, i, l, r;
    cin >> n >> d >> k;
    vl v1(n + 1), v2(n + 1);
    while (k--)
    {
        cin >> l >> r;
        v1[l]++, v2[r]++;
    }
    for (i = 1; i <= n; i++)
        v1[i] += v1[i - 1], v2[i] += v2[i - 1];
    ll index1 = 1, index2 = 1, brother = v1[d], mother = v1[d];
    for (i = d + 1; i <= n; i++)
    {
        ll overlap = v1[i] - v2[i - d], index = i - d + 1;
        if (brother < overlap)
            brother = overlap, index1 = index;
        if (mother > overlap)
            mother = overlap, index2 = index;
    }
    cout << index1 << ' ' << index2 << endl;
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