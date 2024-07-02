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
bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first.first < b.first.first;
}
void solve()
{
    ll n, m, i;
    cin >> n >> m;
    vl v1(n), v2(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < n; i++)
        cin >> v2[i];
    vector<pair<pair<ll, ll>, ll>> v3, v4;
    for (i = 0; i < n; i++)
    {
        v3.push_back({{v1[i], v2[i]}, v1[i] - v2[i]});
    }
    sort(v3.begin(), v3.end(), cmp);
    v4.push_back(v3[0]);
    for (i = 1; i < n; i++)
    {
        if (v3[i - 1].second != v3[i].second)
        {
            if (v4.back().first.first > v3[i].first.first)
                v4.push_back(v3[i]);
        }
    }
    n = v4.size();
    vl c(m);
    for (i = 0; i < m; i++)
        cin >> c[i];
    vl dp(N);
    ll ptr = n;
    for (i = 1; i < N; i++)
    {
        while (ptr > 0 && v4[ptr - 1].first.first == i)
            ptr--;
        if (ptr == n)
            dp[i] = 0;
        else
        {
            dp[i] = 2 + dp[i - v4[ptr].second];
        }
        // cout << i << ' ' << dp[i] << endl;
    }
    ll ans = 0;
    for (i = 0; i < m; i++)
    {
        if (c[i] >= N)
        {
            ll temp = 1 + (c[i] - v4[0].first.first) / v4[0].second;
            c[i] -= (temp * v4[0].second);
            ans += (2 * temp);
        }

        ans += dp[c[i]];
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