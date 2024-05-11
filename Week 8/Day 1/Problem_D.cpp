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
typedef vector<ll> vl;
const ll N = 1e5 + 1;
const ll MOD = 998244353;
void solve()
{
    ll n, k, i;
    cin >> n >> k;
    ll m = sqrt(n);
    ll c = 0;
    for (i = 1; i <= m; i++)
    {
        if (n % i == 0)
        {
            c++;
            if (i != n / i)
                c++;
        }
    }
    if (c < k)
    {
        cout << -1 << endl;
        return;
    }
    c = 0;
    for (i = 1; i <= m; i++)
    {
        if (n % i == 0)
        {
            c++;
            if (c == k)
            {
                cout << i << endl;
                return;
            }
        }
    }
    if (m * m == n)
        m--;
    for (i = m; i >= 1; i--)
    {
        if (n % i == 0)
        {
            c++;
            if (c == k)
            {
                cout << n / i << endl;
                return;
            }
        }
    }
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