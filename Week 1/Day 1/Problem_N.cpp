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
    ll n, num, i;
    cin >> n;
    vector<bool> v1(n + 1, false);
    for (i = 1; i < n; i++)
    {
        cin >> num;
        v1[num] = true;
    }
    for (i = 1; i <= n; i++)
    {
        if (!v1[i])
        {
            cout << i;
            return;
        }
    }
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