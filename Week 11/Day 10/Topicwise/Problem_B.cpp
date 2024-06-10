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
vl v1(N), v2(N);
void solve()
{
    ll n, k, q, l, r, i;
    cin >> n >> k >> q;
    for (i = 1; i <= N; i++)
    {
        v1[i] = 0;
        v2[i] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        cin >> l >> r;
        v1[l]++;
        v1[r + 1]--;
    }
    for (i = 2; i <= N; i++)
        v1[i] += v1[i - 1];
    for (i = 1; i <= N; i++)
    {
        if (v1[i] >= k)
            v2[i]++;
    }
    for (i = 2; i <= N; i++)
        v2[i] += v2[i - 1];
    while (q--)
    {
        cin >> l >> r;
        cout << v2[r] - v2[l - 1] << endl;
    }
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}