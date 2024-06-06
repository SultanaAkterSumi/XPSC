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
#define yes cout << "Yes\n";
#define no cout << "No\n";
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
    ll n, m, p = 0, i, ans = 0, t = 0;
    cin >> n >> m;
    // cout << n << ' ' << m << endl;
    vl v1(n + m + 1), v2(n + m + 1);
    for (i = 0; i < n + m + 1; i++)
        cin >> v1[i];
    for (i = 0; i < n + m + 1; i++)
        cin >> v2[i];
    for (i = 0; i < n + m; i++)
    {
        if (v1[i] > v2[i])
            p++;
        else
            t++;
    }

    ll save1 = -1, save2 = -1;
    if (p == n)
    {
        for (i = 0; i < n + m; i++)
        {
            if (v1[i] > v2[i])
                ans += v1[i];
            else
                ans += v2[i];
        }
        for (i = 0; i < n + m; i++)
        {
            if (v1[i] > v2[i])
                cout << ans - v1[i] + v1[n + m] << ' ';
            else
                cout << ans - v2[i] + v2[n + m] << ' ';
        }
        cout << ans << endl;
    }
    else if (p > n)
    {
        p = 0;
        t = 0;
        for (i = 0; i < n + m; i++)
        {
            if (v1[i] > v2[i])
            {
                if (p < n)
                {
                    p++;
                    ans += v1[i];
                }
                else
                {
                    t++;
                    ans += v2[i];
                    if (save2 == -1)
                        save2 = i;
                }
                if (p == n && save1 == -1)
                    save1 = i;
            }
            else
            {
                if (t < m)
                {
                    t++;
                    ans += v2[i];
                }
                else
                {
                    p++;
                    ans += v1[i];
                }
            }
        }
        for (i = 0; i < n + m; i++)
        {
            if (v1[i] < v2[i] || save1 < i)
                cout << ans - v2[i] + v2[n + m] << ' ';
            else
                cout << ans - v1[i] + v1[save2] - v2[save2] + v2[n + m] << ' ';
        }
        cout << ans << endl;
    }
    else
    {
        p = 0;
        t = 0;

        for (i = 0; i < n + m; i++)
        {
            if (v1[i] < v2[i])
            {
                if (t < m)
                {
                    t++;
                    ans += v2[i];
                }
                else
                {
                    p++;
                    ans += v1[i];
                    if (save2 == -1)
                        save2 = i;
                }
                if (t == m && save1 == -1)
                    save1 = i;
            }
            else
            {
                if (p < n)
                {
                    p++;
                    ans += v1[i];
                }
                else
                {
                    t++;
                    ans += v2[i];
                }
            }
        }

        for (i = 0; i < n + m; i++)
        {
            if (v1[i] > v2[i] || save1 < i)
                cout << ans - v1[i] + v1[n + m] << ' ';
            else
                cout << ans - v2[i] + v2[save2] - v1[save2] + v1[n + m] << ' ';
        }
        cout << ans << endl;
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