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
    ll a = 0, b = 0, n, c = 0, i;
    string s1;
    cin >> s1;
    n = s1.size();
    for (auto it : s1)
    {
        if (it == 'A')
            a++;
        else
            b++;
    }
    if (a && b)
    {
        bool f = false;
        for (i = 1; i < n && !f; i++)
        {
            if (s1[i - 1] == 'B' && s1[i] == 'B')
                f = true;
        }
        if (s1[0] == 'A' && s1[n - 1] == 'A' && !f)
        {
            ll MIN = n;
            for (i = 0; i < n; i++)
            {
                if (s1[i] == 'A')
                    c++;
                else if (c)
                {
                    MIN = min(MIN, c);
                    c = 0;
                }
            }
            if (c)
                MIN = min(MIN, c);
            cout << a - MIN << endl;
        }
        else
            cout << a << endl;
    }
    else
        cout << 0 << endl;
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