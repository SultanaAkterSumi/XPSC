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
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, q, i, l, r;
    cin >> n >> q;
    vl v1(n), v2(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    while (q--)
    {
        cin >> l >> r;
        v2[l - 1]++;
        if (r < n)
            v2[r]--;
    }
    for (i = 1; i < n; i++)
        v2[i] += v2[i - 1];
    sort(v2.begin(), v2.end());
    sort(v1.begin(), v1.end());
    ll ans = 0;
    for (i = 0; i < n; i++)
        ans += (v1[i] * v2[i]);
    cout << ans;
}
int main()
{
    op() int tc = 1;
    // cin>>tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}