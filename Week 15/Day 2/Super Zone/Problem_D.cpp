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
const ll N = 2e5 + 1;
vl opr(N);
void solve()
{
    map<char, vl> m1;
    string s1;
    ll i, n;
    cin >> s1;
    n = s1.size();
    for (i = 0; i < n; i++)
    {
        m1[s1[i]].push_back(i);
    }
    ll ans = INT64_MAX;
    for (auto it : m1)
    {
        vl v1 = it.second;
        ll m = v1.size(), temp1 = 0, temp2, len;

        temp1 = opr[v1[0]];
        len = (n - v1[m - 1] - 1);
        temp2 = opr[len];
        temp1 = max(temp1, temp2);

        for (i = 1; i < m; i++)
        {

            len = v1[i] - v1[i - 1] - 1;
            temp2 = opr[len];
            temp1 = max(temp1, temp2);
        }

        ans = min(ans, temp1);
    }
    cout << ans << endl;
}
int main()
{
    op() int tc = 1;
    ll i;
    for (i = 1; i < N; i++)
    {
        ll bad = i / 2;
        if (i % 2)
            bad++;
        opr[i] = 1 + opr[i - bad];
    }
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}