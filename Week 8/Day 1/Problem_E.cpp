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
const ll N = 2e5 + 9;

// Sieve
bool isprime[1000009];
void Sieve()
{
    memset(isprime, true, sizeof(isprime));
    ll i, j, limit = sqrt(1000009 * 1.) + 2;
    isprime[1] = false;
    for (i = 4; i < 1000009; i += 2)
        isprime[i] = false;
    for (i = 3; i < 1000009; i += 2)
    {
        if (isprime[i])
        {
            if (i < limit)
            {
                for (j = i * i; j < 1000009; j += i * 2)
                    isprime[j] = false;
            }
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    ll t1 = sqrt(n);
    ll i;
    for (i = t1; i >= 1; i--)
    {
        if (n % i == 0 && gcd(i, n / i) == 1)

        {
            cout << i << ' ' << n / i;
            break;
        }
    }
}
int main()
{
    op() int tc = 1;
    Sieve();
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}