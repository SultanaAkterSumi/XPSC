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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i, Max = 1;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        Max = max(Max, v1[i]);
    }
    ll min_value = 1;

    while (Max)
    {
        min_value *= 2;
        Max /= 2;
    }
    min_value /= 2;
    // cout << min_value << endl;
    ll c = 0;
    for (i = 0; i < n; i++)
    {
        if (v1[i] >= min_value)
            c++;
    }
    ll ans = c / 2;
    if (c % 2)
        ans++;
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