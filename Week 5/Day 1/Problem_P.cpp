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
    ll n, m, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    cin >> m;
    vl v2(m);
    for (i = 0; i < m; i++)
        cin >> v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    i = 0;
    ll j = 0, ans = 0;
    while (i < n && j < m)
    {
        if (abs(v1[i] - v2[j]) <= 1)
        {
            ans++;
            i++;
            j++;
        }
        else if (v1[i] < v2[j])
            i++;
        else
            j++;
    }
    cout << ans;
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
