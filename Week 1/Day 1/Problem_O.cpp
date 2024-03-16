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
    ll n, ans = 0, i;
    string s1;
    char ch;
    cin >> n >> ch >> s1;

    if (ch == 'g')
    {
        cout << 0 << endl;
        return;
    }
    ll save = -1;
    for (i = 0; i < n; i++)
    {
        if (save == -1 && s1[i] == ch)
            save = i;
        else if (save != -1 && s1[i] == 'g')
        {
            ans = max(ans, i - save);
            save = -1;
        }
    }
    if (save != -1)
    {
        ll t1 = n - save;
        for (i = 0; i < n; i++)
        {
            if (s1[i] == 'g')
                break;
            t1++;
        }
        ans = max(ans, t1);
        cout << ans << endl;
    }
    else
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