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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 1;

void solve()
{
    ll n, x, y, i, j;
    cin >> n;
    vector<ll> a(n);
    for (i = 0; i < n; i++)
        cin >> a[i];
    bool f1 = true, f2 = false;
    if (n == 1 && a[0] == 1)
    {
        yes return;
    }
    x = a[n - 1];
    y = n - 1;
    for (i = 0; i < n; i++)
    {
        if (i == y)
        {
            if (a[i] != y + 1)
                f1 = false;
            break;
        }
        if (a[i] < (y + 1) || a[i] > (y + 1))
        {
            f1 = false;
            break;
        }
        else
        {
            x--;
            if (x == 0)
            {
                for (j = y - 1; j > i; j--)
                {
                    if (a[j] != a[y])
                    {
                        x = a[j] - a[y];
                        y = j;
                        break;
                    }
                }
                if (i == j)
                    f2 = true;
            }
        }
        if (f2)
            break;
    }
    if (f1 && n == a[0])
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