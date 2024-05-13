#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 1e5 + 1;
const ll MOD = 998244353;
bool isPrime(ll n)
{
    if (n == 1)
        return false;
    ll i, m = sqrt(n);
    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve()
{
    ll a, b, i;
    cin >> a >> b;
    while (1)
    {
        ll p = gcd(a, b);
        if (p == 1)
            break;
        b /= p;
    }
    if (b == 1)
        yes else no
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}