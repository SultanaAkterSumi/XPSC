#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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
    ll n, i, ans = 0;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    bool f1 = false, f2 = false; // 1->negative, 2->positive
    ll temp1, temp2;
    for (i = 0; i < n; i++)
    {
        if (v1[i] < 0)
        {
            if (f2)
            {
                ans += temp2;
                temp1 = v1[i];
                f1 = true;
                f2 = false;
            }
            else
            {
                if (!f1)
                {
                    temp1 = v1[i];
                    f1 = true;
                }
                else
                {
                    temp1 = max(temp1, v1[i]);
                }
            }
        }
        else
        {
            if (f1)
            {
                ans += temp1;
                temp2 = v1[i];
                f2 = true;
                f1 = false;
            }
            else
            {
                if (!f2)
                {
                    temp2 = v1[i];
                    f2 = true;
                }
                else
                {
                    temp2 = max(temp2, v1[i]);
                }
            }
        }
    }
    if (f1)
        ans += temp1;
    else
        ans += temp2;
    cout << ans << endl;
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