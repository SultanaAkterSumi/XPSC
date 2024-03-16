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
    ll n, m;
    cin >> n >> m;
    ll i = 0, j = 0;
    vl v1(n), v2(m);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < m; i++)
        cin >> v2[i];
    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
        {
            cout << v1[i] << ' ';
            i++;
        }
        else
        {
            cout << v2[j] << ' ';
            j++;
        }
    }
    while (i < n)
    {
        cout << v1[i] << ' ';
        i++;
    }
    while (j < m)
    {
        cout << v2[j] << ' ';
        j++;
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