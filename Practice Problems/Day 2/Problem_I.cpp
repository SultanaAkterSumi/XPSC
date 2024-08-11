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
const ll N = 2e5 + 1;
vector<pll> v1;
void Binary_Search(ll l, ll r)
{
    ll low = 0, high = v1.size() - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v1[mid].first >= l && v1[mid].second <= r)
        {
            cout << v1[mid].first << ' ' << v1[mid].second << endl;
            return;
        }
        else if (v1[mid].first < l)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << -1 << ' ' << -1 << endl;
}
void solve()
{
    v1.clear();
    ll n, i, num1, num2;
    cin >> n;
    cin >> num1;
    for (i = 2; i <= n; i++)
    {
        cin >> num2;
        if (num1 != num2)
        {
            v1.push_back({i - 1, i});
            // cout << num1 << ' ' << num2 << endl;
        }
        num1 = num2;
    }
    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        if (v1.size() == 0)
            cout << -1 << ' ' << -1 << endl;
        else
            Binary_Search(l, r);
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