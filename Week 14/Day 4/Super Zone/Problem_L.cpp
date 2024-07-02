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
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}
void solve()
{
    ll i, j, n, m, h, a, r_s, r_p;
    cin >> n >> m >> h;
    vl v1;
    vector<pair<ll, ll>> v;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> a;
            v1.push_back(a);
        }
        sort(v1.begin(), v1.end());
        vector<ll> v2(m);
        v2[0] = v1[0];
        for (j = 1; j < m; j++)
            v2[j] = (v2[j - 1] + v1[j]);
        ll score = 0, penalty = 0, time = 0;
        for (j = 0; j < m; j++)
        {
            time += v1[j];
            if (time > h)
                break;
            score++;
            penalty += v2[j];
        }
        if (i == 1)
        {
            r_s = score;
            r_p = penalty;
        }
        v.push_back({score, penalty});
        v1.clear();
        v2.clear();
    }
    sort(v.begin(), v.end(), cmp);
    for (i = 0; i < n; i++)
    {
        if (v[i].first == r_s && v[i].second == r_p)
            break;
    }

    cout << i + 1 << endl;
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