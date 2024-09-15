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
    ll n, m, s, q, i;
    cin >> n >> m >> q;
    vl v1(m);
    for (i = 0; i < m; i++)
    {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    for (i = 0; i < q; i++)
    {
        cin >> s;
        ll l = 0, r = m - 1, mid, res1 = 0, res2 = n + 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v1[mid] < s)
            {
                if (res1 < v1[mid])
                    res1 = v1[mid];
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        l = 0, r = m - 1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v1[mid] > s)
            {
                if (res2 > v1[mid])
                    res2 = v1[mid];
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (res1 == 0)
        {
            cout << res2 - 1 << endl;
        }
        else if (res2 == n + 1)
        {
            cout << n - res1 << endl;
        }
        else
        {
            ll temp = res2 - res1 - 1;
            if (temp % 2)
                cout << 1 + temp / 2 << endl;
            else
                cout << temp / 2 << endl;
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