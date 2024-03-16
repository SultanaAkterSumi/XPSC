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
    ll n, m, i, j, ans = 0;
    cin >> n >> m;
    vl v1(n), v2(m);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < m; i++)
        cin >> v2[i];
    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        ll c1 = 0, c2 = 0, curr1 = v1[i];
        while (i < n && curr1 == v1[i])
        {
            c1++;
            i++;
        }
        while (j < m && curr1 > v2[j])
        {
            j++;
        }
        while (j < m && curr1 == v2[j])
        {
            c2++;
            j++;
        }
        ans += (c1 * c2);
    }
    cout << ans << endl;
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