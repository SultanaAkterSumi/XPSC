#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define gcd(a, b) __gcd(a, b)
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, m, h, i;
    cin >> n >> m >> h;
    vl v1(n), v2(m);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < m; i++)
        cin >> v2[i];
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    ll x = min(n, m), ans = 0;
    for (i = 0; i < x; i++)
    {
        ll t1 = v1[i], t2 = h * v2[i];
        ans += (min(t1, t2));
    }
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