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
const ll N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, k, s = 0, i;
    cin >> n >> k;
    vl v1(n + 1), v2(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v1[i];
        s += v1[i];
    }
    v1[0] = ((n * (n + 1)) / 2) - s;
    s = (k) % (n + 1);
    for (i = 0; i <= n; i++)
    {
        v2[(i + s) % (n + 1)] = v1[i];
    }
    for (i = 1; i <= n; i++)
        cout << v2[i] << ' ';
    cout << endl;
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