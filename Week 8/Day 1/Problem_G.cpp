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
const ll N = 1e5 + 1;
const ll MOD = 998244353;
void solve()
{
    ll n, num, i, j;
    cin >> n;
    vl v1(N);
    vector<bool> v2(N, true);
    while (n--)
    {
        cin >> num;
        v1[num]++;
    }
    ll ans = 1;
    for (i = 2; i < N; i++)
    {
        if (v2[i])
        {
            ll c = 0;
            for (j = i; j < N; j += i)
            {
                v2[j] = false;
                c += v1[j];
            }
            ans = max(ans, c);
        }
    }
    cout << ans << endl;
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}