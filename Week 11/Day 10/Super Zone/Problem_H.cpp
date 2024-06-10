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
    ll n, i, j, k;
    cin >> n;
    vector<string> v1;
    vector<vl> v2(6, vl(46, 0));
    string s1;

    for (i = 0; i < n; i++)
    {
        cin >> s1;
        v1.push_back(s1);
        ll sum = 0;
        for (auto it : s1)
        {
            sum += (it - '0');
        }
        v2[s1.size()][sum]++;
    }
    // for (i = 1; i <= 5; i++)
    // {
    //     for (ll j = 1; j <= 45; j++)
    //         cout << v2[i][j] << ' ';
    //     cout << endl;
    // }
    ll ans = 0;
    for (i = 0; i < n; i++)
    {
        s1 = v1[i];
        ll m = s1.size();
        if (m % 2)
        {
            for (j = 1; j <= 5 && m >= (j + m) / 2; j += 2)
            {
                ll sum = 0;
                for (k = 0; k < ((j + m) / 2); k++)
                    sum += (s1[k] - '0');
                for (; k < m; k++)
                    sum -= (s1[k] - '0');
                if (sum > 0)
                {
                    ans += v2[j][sum];
                }
            }
        }
        else
        {
            for (j = 2; j <= 4 && m >= (j + m) / 2; j += 2)
            {
                ll sum = 0;
                for (k = 0; k < ((j + m) / 2); k++)
                    sum += (s1[k] - '0');
                for (; k < m; k++)
                    sum -= (s1[k] - '0');
                if (sum > 0)
                {
                    ans += v2[j][sum];
                }
            }
        }
    }
    // cout << ans << endl;
    for (i = 0; i < n; i++)
    {
        s1 = v1[i];
        ll m = s1.size();
        if (m % 2)
        {
            for (j = 1; j <= 5 && m > (j + m) / 2; j += 2)
            {
                ll sum = 0, c = ((j + m) / 2);
                for (k = m - 1; c > 0; k--)
                {
                    sum += (s1[k] - '0');
                    c--;
                }
                for (; k >= 0; k--)
                    sum -= (s1[k] - '0');
                if (sum > 0)
                {
                    ans += v2[j][sum];
                }
            }
        }
        else
        {
            for (j = 2; j <= 4 && m > (j + m) / 2; j += 2)
            {
                ll sum = 0, c = ((j + m) / 2);
                for (k = m - 1; c > 0; k--)
                {
                    sum += (s1[k] - '0');
                    c--;
                }
                for (; k >= 0; k--)
                    sum -= (s1[k] - '0');
                if (sum > 0)
                {
                    ans += v2[j][sum];
                }
            }
        }
    }
    cout << ans << endl;
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