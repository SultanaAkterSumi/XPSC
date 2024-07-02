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
    ll n, k, i, j, c = 0;
    string s1;
    cin >> n >> k >> s1;
    i = 0;
    while (i < n)
    {
        if (s1[i] == '0')
        {
            bool f = true;
            ll temp = min(n - 1, i + k);
            for (j = i + 1; j <= temp; j++)
            {
                if (s1[j] == '1')
                {
                    f = false;
                    break;
                }
            }
            if (f)
            {
                // cout << i << endl;
                c++;
                i += (k + 1);
            }
            else
                i = j + k + 1;
        }
        else
            i += (k + 1);
    }
    cout << c << endl;
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