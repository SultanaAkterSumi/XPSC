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
const ll INF = 1e9 + 1;
void solve()
{
    ll n, i, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v1;
    for (i = 0; i < n; i++)
    {
        pair<ll, ll> p1;
        cin >> p1.first;
        p1.second = i + 1;
        v1.push_back(p1);
    }

    sort(v1.begin(), v1.end());
    // for (i = 0; i < n; i++)
    // {
    //     cout << v1[i].first << ' ' << v1[i].second << endl;
    // }
    vector<pair<ll, ll>> v2;
    v2.push_back({v1[n - 1].second, v1[n - 1].second});
    for (i = n - 2; i >= 0; i--)
    {
        v2.push_back({min(v1[i].second, v2.back().first), max(v1[i].second, v2.back().second)});
    }
    reverse(v2.begin(), v2.end());
    // for (i = 0; i < n; i++)
    // {
    //     cout << v2[i].first << ' ' << v2[i].second << endl;
    // }
    ll c = 1;
    i = 0;
    while (i < n && c <= k)
    {
        if (c != v1[i].first)
        {
            cout << 0 << ' ';
            c++;
        }
        else
        {
            ll l = v2[i].first, r = v2[i].second;
            i++;
            while (i < n && v1[i].first == c)
            {

                l = min(l, v2[i].first);
                r = max(l, v2[i].second);
                i++;
            }
            cout << 2 * (r - l + 1) << ' ';
            c++;
        }
    }

    while (c <= k)
    {
        cout << 0 << ' ';
        c++;
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