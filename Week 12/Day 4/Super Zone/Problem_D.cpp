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
    ll n, i;
    cin >> n;
    vector<pair<ll, ll>> v1;
    for (i = 0; i < n; i++)
    {
        pair<ll, ll> p1;
        cin >> p1.first;
        p1.second = i + 1;
        v1.push_back(p1);
    }
    sort(v1.begin(), v1.end());
    if (v1[0].first == v1[n - 1].first)
    {
        no return;
    }
    // for (i = 0; i < n; i++)
    // {
    //     cout << v1[i].first << ' ' << v1[i].second << endl;
    // }
    yes
        i = 1;
    while (v1[i].first == v1[0].first)
    {
        i++;
    }
    ll save = i;
    while (v1[i].first == v1[save].first)
    {
        cout << v1[0].second << ' ' << v1[i].second << endl;
        i++;
    }
    i = 1;
    while (v1[i].first == v1[0].first)
    {
        cout << v1[i].second << ' ' << v1[save].second << endl;
        i++;
    }
    i = save + 1;
    while (1)
    {
        while (i < n && v1[i].first == v1[save].first)
        {
            i++;
        }
        if (i == n)
            break;
        ll temp = save;
        save = i;
        while (i < n && v1[i].first == v1[save].first)
        {
            cout << v1[temp].second << ' ' << v1[i].second << endl;
            i++;
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