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
    ll n, m, i, j, num;
    cin >> n >> m;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    i = 0;
    for (j = 0; j < m; j++)
    {
        cin >> num;
        while (i < n && v1[i] < num)
        {
            i++;
        }
        cout << i << ' ';
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