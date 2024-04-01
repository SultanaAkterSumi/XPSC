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
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n);
    set<ll> s1;
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (s1.count(v1[i]))
        {
            cout << i + 1 << endl;
            return;
        }
        s1.insert(v1[i]);
    }
    cout << 0 << endl;
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}