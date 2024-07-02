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
    ll n, j, i;
    string s1;
    cin >> n >> s1;
    ll ans = 261;
    for (j = 0; j < n - 1; j++)
    {
        ll temp1 = 10 * (s1[j] - '0') + (s1[j + 1] - '0');
        for (i = 0; i < j; i++)
        {
            ll temp2 = s1[i] - '0';
            if (temp1 <= 1 || temp2 <= 1)
                temp1 *= temp2;
            else
                temp1 += temp2;
        }
        for (i = j + 2; i < n; i++)
        {
            ll temp2 = s1[i] - '0';
            if (temp1 <= 1 || temp2 <= 1)
                temp1 *= temp2;
            else
                temp1 += temp2;
        }
        ans = min(ans, temp1);
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