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
    ll n, q, i, sum = 0, l, r, k;
    cin >> n >> q;
    vl v1(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v1[i];
        sum += v1[i];
        v1[i] += v1[i - 1];
    }
    while (q--)
    {
        cin >> l >> r >> k;
        ll t1 = sum - (v1[r] - v1[l - 1]) + (k * (r - l + 1));
        if (t1 % 2)
            yes else no
    }
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