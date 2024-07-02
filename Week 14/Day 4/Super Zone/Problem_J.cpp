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
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}
void solve()
{
    ll n, i, num;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    vector<pair<ll, ll>> v2;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        v2.push_back({v1[i] - num, i + 1});
    }
    sort(v2.begin(), v2.end(), cmp);
    ll ans = 1;
    for (i = 1; i < n; i++)
    {
        if (v2[i].first == v2[0].first)
            ans++;
        else
            break;
    }
    cout << ans << endl;
    for (i = 0; i < ans; i++)
    {
        cout << v2[i].second << ' ';
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