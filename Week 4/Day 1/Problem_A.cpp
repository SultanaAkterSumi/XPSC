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
    ll n, i;
    cin >> n;
    vl v1(n + 1);
    cin >> v1[1];
    for (i = 2; i <= n; i++)
    {
        cin >> v1[i];
        v1[i] = (v1[i] ^ v1[i - 1]);
    }
    ll ans = v1[n];
    ll temp = (v1[n] ^ v1[1]);
    ans = min(ans, temp);
    for (i = 2; i < n; i++)
    {
        temp = ((v1[n] ^ v1[i]) ^ v1[i - 1]);
        ans = min(ans, temp);
    }
    ans = min(ans, v1[n - 1]);
    cout << ans << endl;
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