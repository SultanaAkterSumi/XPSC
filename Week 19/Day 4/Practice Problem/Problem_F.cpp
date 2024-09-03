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
const ll N = 2e5 + 1;

void solve()
{
    ll n, m, t = 0, l, i, j, mex;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> l;
        vl v1(l);
        for (j = 0; j < l; j++)
        {
            cin >> v1[j];
        }
        sort(v1.begin(), v1.end());
        mex = 0, j = 0;
        while (j < l)
        {
            if (v1[j] != mex)
                break;
            else
            {
                mex++, j++;
                while (j < l && v1[j - 1] == v1[j])
                    j++;
            }
        }
        mex++;
        while (j < l)
        {
            if (v1[j] != mex)
                break;
            else
            {
                mex++, j++;
                while (j < l && v1[j - 1] == v1[j])
                    j++;
            }
        }
        t = max(t, mex);
    }
    if (m <= t)
        cout << (m + 1) * t << endl;
    else
        cout << (t * (t + 1)) + ((m * (m + 1)) / 2) - (t * (t + 1)) / 2 << endl;
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