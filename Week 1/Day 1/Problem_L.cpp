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
    ll n, i, ans = 0;
    cin >> n;
    vl v1(n + 1);
    for (i = 1; i <= n; i++)
        cin >> v1[i];
    ll curr = 1;
    i = 1;
    while (i <= n)
    {
        if (v1[i] > curr)
        {
            ans += (v1[i] - curr);
            curr = v1[i] + 1;
            i++;
        }
        else
        {
            curr++;
            i++;
        }
    }
    cout << ans << endl;
}
int main()
{
    op() int tc = 1;
    // Sieve();
    cin >> tc;
    // cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case "<<t<<": ";
        // cout<<"Scenario #"<<t<<": ";
        solve();
    }
}