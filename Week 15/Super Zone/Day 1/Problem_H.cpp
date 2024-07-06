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
const ll N = 1e6 + 1;

void solve()
{
    string a, b;
    cin >> a >> b;
    ll sz1, sz2;
    sz1 = a.size();
    sz2 = b.size();
    if (a[0] == b[0])
    {
        yes
                cout
            << a[0] << "*\n";
    }
    else if (a[sz1 - 1] == b[sz2 - 1])
    {
        yes
                cout
            << "*" << a[sz1 - 1] << endl;
    }
    else
    {
        ll i, j, f1 = 0;
        for (i = 0; i < sz1 - 1; i++)
        {
            for (j = 0; j < sz2 - 1; j++)
            {
                if (a[i] == b[j] && a[i + 1] == b[j + 1])
                {
                    f1 = 1;
                    break;
                }
            }
            if (f1)
                break;
        }
        if (f1)
        {
            yes
                    cout
                << '*' << a[i] << a[i + 1] << "*\n";
        }
        else
            no
    }
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