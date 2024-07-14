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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 1;

void solve()
{
    ll n, i, m;
    string s1;
    cin >> n >> s1;
    string ans(n, '.');

    if (s1[0] == '9')
    {
        ll carry = 0;

        for (i = n - 1; i >= 0; i--)
        {
            m = carry + (s1[i] - '0');
            if (m > 1)
            {
                carry = 1;
                m = 11 - m;
            }
            else
            {
                carry = 0;
                m = 1 - m;
            }
            ans[i] = char('0' + m);
        }
    }
    else
    {
        for (i = n - 1; i >= 0; i--)
        {
            m = 9 - (s1[i] - '0');
            ans[i] = char('0' + m);
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