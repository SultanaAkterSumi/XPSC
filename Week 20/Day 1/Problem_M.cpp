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
const ll N = 1e18;
void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n), v2(n), v3(n), v4(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    v2[0] = 1;
    v2[n - 1] = n - 2;
    for (i = 1; i < n - 1; i++)
    {
        if (abs(v1[i - 1] - v1[i]) < abs(v1[i + 1] - v1[i]))
            v2[i] = i - 1;
        else
            v2[i] = i + 1;
    }
    for (i = 1; i < n; i++)
    {
        if (v2[i - 1] == i)
            v3[i] = 1LL;
        else
            v3[i] = abs(v1[i - 1] - v1[i]);
        v3[i] += v3[i - 1];
    }
    for (i = n - 2; i >= 0; i--)
    {
        if (v2[i + 1] == i)
            v4[i] = 1LL;
        else
            v4[i] = abs(v1[i + 1] - v1[i]);
        v4[i] += v4[i + 1];
    }
    ll q, x, y;
    cin >> q;
    for (i = 0; i < q; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        if (x < y)
        {
            if (x == 0)
                cout << v3[y] << endl;
            else
                cout << v3[y] - v3[x] << endl;
        }
        else
        {
            if (x == n - 1)
                cout << v4[y] << endl;
            else
                cout << v4[y] - v4[x] << endl;
        }
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