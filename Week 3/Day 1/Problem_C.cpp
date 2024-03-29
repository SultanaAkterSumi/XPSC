#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define gcd(a, b) __gcd(a, b)
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, m, i, j;
    cin >> n >> m;
    vector<vl> v1(n, vl(m));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> v1[i][j];
        }
    }
    ll ans = 0, temp = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            temp = v1[i][j];
            ll t1, t2;
            t1 = i - 1;
            t2 = j - 1;
            while (t1 >= 0 && t2 >= 0)
            {
                temp += v1[t1][t2];
                t1--;
                t2--;
            }
            t1 = i - 1;
            t2 = j + 1;
            while (t1 >= 0 && t2 < m)
            {
                temp += v1[t1][t2];
                t1--;
                t2++;
            }
            t1 = i + 1;
            t2 = j - 1;
            while (t1 < n && t2 >= 0)
            {
                temp += v1[t1][t2];
                t1++;
                t2--;
            }
            t1 = i + 1;
            t2 = j + 1;
            while (t1 < n && t2 < m)
            {
                temp += v1[t1][t2];
                t1++;
                t2++;
            }
            ans = max(ans, temp);
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
        solve();
    }
}