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
    ll n, num;
    cin >> n;
    ll ans = 0;
    vl v1;
    while (n--)
    {
        cin >> num;
        if (num % 2)
            v1.push_back(num);
        else
            ans += num;
    }

    sort(v1.begin(), v1.end());
    n = v1.size();
    while (n >= 2)
    {
        ans += v1.back();
        v1.pop_back();
        ans += v1.back();
        v1.pop_back();
        n -= 2;
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