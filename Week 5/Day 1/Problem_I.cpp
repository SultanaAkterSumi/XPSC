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
    string s1, s2;
    cin >> s1 >> s2;
    ll n1 = s1.size(), n2 = s2.size();
    if (n1 > n2)
    {
        swap(s1, s2);
        swap(n1, n2);
    }
    // cout << s1 << endl
    //      << s2 << endl;
    ll ans = n1 + n2;
    ll i, j;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
        {
            ll c = 0, x = i, y = j;
            while (x < n1 && y < n2)
            {
                if (s1[x] == s2[y])
                {
                    // cout << s1[x] << ' ' << s2[y] << endl;
                    x++;
                    y++;
                    c++;
                }
                else
                    break;
            }
            // cout << i << ' ' << j << ' ' << c << endl;
            ans = min(ans, n1 + n2 - (2 * c));
        }
    }
    cout << ans << endl;
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
