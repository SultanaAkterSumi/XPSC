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

void solve()
{
    ll n, i, j, num;
    cin >> n;
    map<ll, ll> m1;
    vector<bool> v1(n + 1, false);
    for (i = 0; i < n; i++)
    {
        cin >> num;
        if (num <= n)
            m1[num]++;
    }
    ll ans = 0;
    for (i = n; i >= 1; i--)
    {
        if (!v1[i])
        {
            ll t1 = sqrt(i), t2 = 0;
            for (j = 1; j <= t1; j++)
            {
                if (i % j == 0)
                {
                    t2 += m1[j];
                    v1[j] = true;
                    v1[i / j] = true;
                    if (j != i / j)
                        t2 += m1[i / j];
                }
            }
            ans = max(ans, t2);
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