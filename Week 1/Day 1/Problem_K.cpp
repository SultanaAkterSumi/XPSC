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
    ll n, a = 0, b = 0, c = 0, i;
    cin >> n;
    string s1;
    map<string, ll> m1, m2, m3;
    for (i = 1; i <= n; i++)
    {
        cin >> s1;
        m1[s1] = 1;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> s1;
        m2[s1] = 1;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> s1;
        m3[s1] = 1;
    }
    for (auto it : m1)
    {

        if (m2.count(it.first) && m3.count(it.first))
            continue;
        else if (m2.count(it.first) || m3.count(it.first))
            a++;
        else
            a += 3;
    }
    for (auto it : m2)
    {

        if (m1.count(it.first) && m3.count(it.first))
            continue;
        else if (m1.count(it.first) || m3.count(it.first))
            b++;
        else
            b += 3;
    }
    for (auto it : m3)
    {
        if (m2.count(it.first) && m1.count(it.first))
            continue;
        else if (m2.count(it.first) || m1.count(it.first))
            c++;
        else
            c += 3;
    }
    cout << a << ' ' << b << ' ' << c << endl;
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