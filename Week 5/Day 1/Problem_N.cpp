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
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v1[i];
    }
    i = 1;
    ll k = n, j = 2, Max = n;
    while (i < k)
    {
        if (v1[i] == Max)
        {
            i++;
            Max--;
        }
        else if (v1[k] == Max)
        {
            k--;
            Max--;
        }
        else
            break;
    }
    if (k - i < 2)
    {
        no return;
    }
    j = i + 1;
    while (i < j && j < k)
    {
        if (v1[j] > v1[i] && v1[j] > v1[k])
        {
            yes cout << i << ' ' << j << ' ' << k << endl;
            return;
        }
        else
            j++;
    }
    no
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
