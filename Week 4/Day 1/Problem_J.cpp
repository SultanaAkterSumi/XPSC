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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i, c = 1;
    cin >> n;
    vl v1;
    while (n)
    {
        v1.push_back(n % 2);
        n /= 2;
    }
    ll m = v1.size();
    i = m - 2;
    while (i >= 0)
    {
        if (v1[i] == 1)
            break;
        i--;
    }
    while (i >= 0)
    {
        if (v1[i] == 0)
        {
            c *= 2;
        }
        i--;
    }
    cout << c << endl;
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