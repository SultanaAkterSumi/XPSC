#include <bits/stdc++.h>
using namespace std;

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
const ll N = 1e6 + 1;
vector<pair<ll, ll>> v1;
string s1;
ll dfs(ll source)
{
    ll temp = 0;
    if (s1[source] != 'L')
        temp++;
    if (v1[source].first >= 0)
    {
        temp += dfs(v1[source].first);
    }
    ll temp1 = 0;
    if (s1[source] != 'R')
        temp1++;
    if (v1[source].second >= 0)
    {
        temp1 += dfs(v1[source].second);
    }

    if (v1[source].first == -1 && v1[source].second == -1)
        return 0LL;
    if (v1[source].first >= 0 && v1[source].second >= 0)
        return min(temp, temp1);
    if (v1[source].first >= 0)
        return temp;
    else
        return temp1;
}
void solve()
{
    ll n, i;
    cin >> n >> s1;

    for (i = 0; i < n; i++)
    {
        pair<ll, ll> p1;
        cin >> p1.first >> p1.second;
        p1.first -= 1;
        p1.second -= 1;
        v1.push_back(p1);
    }

    ll t1 = 0;
    ll ans = dfs(t1);
    cout << ans << endl;
    v1.clear();
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