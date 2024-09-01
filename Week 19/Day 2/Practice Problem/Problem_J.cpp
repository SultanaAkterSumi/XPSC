#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long ll;
typedef vector<ll> vl;
#define yes cout << "YES\n";
#define no cout << "NO\n";
void solve()
{
    ll n, i;
    cin >> n;
    string s1;
    cin >> s1;
    ll t1 = n - 3;
    ll ans = 0;
    i = 0;
    while (1)
    {
        if (i > n - 3)
            break;
        if (s1[i] == 'm' && s1[i + 1] == 'a' && s1[i + 2] == 'p')
        {
            if (i <= n - 5 && s1[i + 3] == 'i' && s1[i + 4] == 'e')
            {
                ans++;
                i += 5;
            }
            else
            {
                ans++;
                i += 3;
            }
        }
        else if (s1[i] == 'p' && s1[i + 1] == 'i' && s1[i + 2] == 'e')
        {
            ans++;
            i += 3;
        }
        else
            i++;
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