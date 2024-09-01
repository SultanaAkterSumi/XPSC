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
const ll N = -2e7;
const ll M = 2e8;
bool cmp(pair<ll, string> a, pair<ll, string> b)
{
    return a.first < b.first;
}
void solve()
{
    ll n, i;
    string s1, s2;
    cin >> n >> s1;
    vl v1(26);
    for (i = 0; i < n; i++)
    {
        v1[s1[i] - 'a']++;
    }
    ll c = 0;
    while (c < n)
    {
        for (i = 0; i < 26 && c < n; i++)
        {
            if (v1[i])
            {
                s2.push_back(char(i + 'a'));
                v1[i]--;
                c++;
            }
        }
    }
    cout << s2 << endl;
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