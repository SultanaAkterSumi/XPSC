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
    return a.second < b.second;
}
void solve()
{
    ll n, i, j, num;
    cin >> n;
    vector<pair<ll, ll>> v1;
    for (i = 0; i < n; i++)
    {
        pair<ll, ll> p1;
        cin >> p1.first >> p1.second;
        p1.second++;
        for (j = 1; j < p1.first; j++)
        {
            cin >> num;
            p1.second = max(p1.second, num - j + 1);
        }
        v1.push_back(p1);
    }
    sort(v1.begin(), v1.end(), cmp);
    ll ans = v1[0].second, current = v1[0].second;
    for (i = 0; i < n; i++)
    {
        if (v1[i].second <= current)
        {
            current += v1[i].first;
        }
        else
        {
            ans += (v1[i].second - current);
            current += (v1[i].first + v1[i].second - current);
        }
    }
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