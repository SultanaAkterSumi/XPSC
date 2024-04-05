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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;
vl dec_palindrom;
bool is_palindrom(ll num)
{
    string s1 = to_string(num);
    ll i, n = s1.size();
    ll m = n / 2;
    for (i = 0; i < m; i++)
    {
        if (s1[i] != s1[n - i - 1])
            return false;
    }
    return true;
}
void solve()
{
    ll a, b;
    cin >> a >> b;
    ll a1 = a, b1 = b;
    ll x = 0, temp = 1;
    while (a && b)
    {
        if (a % 2 && b % 2)
            x += temp;
        temp *= 2;
        a /= 2;
        b /= 2;
    }
    cout << (a1 ^ x) + (b1 ^ x) << endl;
}
int main()
{
    op()

        int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}