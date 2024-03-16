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

void solve()
{
    ll s, t, i, j, k, ans = 0;
    cin >> s >> t;
    for (i = 0; i <= 100; i++)
    {
        for (j = 0; j <= 100; j++)
        {
            for (k = 0; k <= 100; k++)
            {

                if (i * j * k <= t && i + j + k <= s)
                    ans++;
            }
        }
    }
    cout << ans;
}
int main()
{
    op() int tc = 1;
    // Sieve();
    // cin >> tc;
    // cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case "<<t<<": ";
        // cout<<"Scenario #"<<t<<": ";
        solve();
    }
}