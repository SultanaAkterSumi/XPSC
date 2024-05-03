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
    ll n, i, j, ans = 0, num;
    cin >> n;
    vl v1;
    vector<bool> v2(n + 1, false);
    for (i = 0; i < n; i++)
    {
        cin >> num;
        if (num <= n && !v2[num])
            v2[num] = true;
        else
            v1.push_back(num);
    }

    sort(v1.begin(), v1.end());
    j = 0;
    for (i = 1; i <= n; i++)
    {
        if (!v2[i])
        {
            ll temp = (v1[j] - 1) - (v1[j] / 2);
            j++;
            if (i > temp)
            {
                cout << -1 << endl;
                return;
            }
            ans++;
        }
    }

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