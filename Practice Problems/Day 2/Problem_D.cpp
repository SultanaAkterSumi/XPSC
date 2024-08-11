#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 1e5 + 1;
const ll MOD = 998244353;
vl v1[1009];
void solve()
{
    ll n, i, res;
    cin >> n;
    vl v2(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v2[i];
    vl v3(1009, -1);
    for (i = 1; i <= n; i++)
        v3[v2[i]] = i;
    res = 0;
    for (i = 1; i <= 1000; i++)
    {
        if (v3[i] == -1)
            continue;
        else if (i == 1)
        {
            res = max(res, 2 * v3[i]);
            continue;
        }
        else
        {
            for (auto x : v1[i])
            {
                if (v3[x] != -1)
                    res = max(res, (v3[i] + v3[x]));
            }
        }
    }
    if (res)
        cout << res << '\n';
    else
        cout << "-1\n";
}
int main()
{
    op() int tc = 1;
    ll i, j;
    for (i = 1; i <= 1000; i++)
    {
        for (j = 1; j <= 1000; j++)
        {
            if (gcd(i, j) == 1)
                v1[i].push_back(j);
        }
    }
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}