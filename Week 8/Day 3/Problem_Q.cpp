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
    ll n, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    ll gcd1 = v1[0];
    for (i = 2; i < n; i += 2)
        gcd1 = gcd(gcd1, v1[i]);
    bool f = true;
    for (i = 1; i < n; i += 2)
    {
        if (v1[i] % gcd1 == 0)
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << gcd1 << endl;
        return;
    }
    gcd1 = v1[1];
    for (i = 3; i < n; i += 2)
        gcd1 = gcd(gcd1, v1[i]);
    f = true;
    for (i = 0; i < n; i += 2)
    {
        if (v1[i] % gcd1 == 0)
        {
            f = false;
            break;
        }
    }
    if (f)
        cout << gcd1 << endl;
    else
        cout << 0 << endl;
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