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
    ll n, m, i, j;
    cin >> n >> m;
    vector<vl> v1(n + 1, vl(m + 1));
    if (isPrime(n) && m == 4)
    {
        ll s = 1;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                v1[i][j] = s;
                s++;
            }
        }
    }
    else
    {
        ll s = 1;
        ll k = m / 2;
        if (m % 2)
            k++;
        for (i = 1; i <= k; i++)
        {
            for (j = 1; j <= n; j++)
            {
                v1[j][i] = s;
                s++;
            }
            s += n;
        }
        s = 1 + n;
        for (; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
            {
                v1[j][i] = s;
                s++;
            }
            s += n;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
            cout << v1[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
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