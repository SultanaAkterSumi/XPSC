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
const ll N = 9;

void solve()
{
    ll n, m, s, q, a, b;
    cin >> n >> m >> q;
    cin >> a >> b >> s;
    if (a > b)
        swap(a, b);
    if (s < a)
        cout << a - 1 << endl;
    else if (s > b)
        cout << n - b << endl;
    else
    {
        ll temp = b - a - 1;
        if (temp % 2)
            cout << 1 + temp / 2 << endl;
        else
            cout << temp / 2 << endl;
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