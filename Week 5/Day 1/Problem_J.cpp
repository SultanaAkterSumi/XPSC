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
    ll a, b, n, num, ans, i;
    cin >> a >> b >> n;
    ans = 0;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        if (a == 1)
            continue;
        ans += b;
        b = 0;
        b += num;
        b = min(b, a);
        if (b == a)
            b--;
    }
    ans += b;
    if (a == 1)
        cout << 1 << endl;
    else
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
