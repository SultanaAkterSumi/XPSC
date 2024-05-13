#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
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
    ll n;
    cin >> n;
    ll a = 1 + n;
    while (!isPrime(a))
    {
        a++;
    }
    ll b = a + n;
    while (!isPrime(b))
    {
        b++;
    }
    cout << a * b << endl;
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