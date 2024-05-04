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
    ll n, k, i, ans = 0, num;
    cin >> n >> k;
    vl v1, v2;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        if (num > 0)
            v1.push_back(num);
        if (num < 0)
            v2.push_back(abs(num));
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    n = v1.size();
    if (n)
    {
        ll temp = n % k, save;
        if (temp)
        {
            ans += (2 * v1[temp - 1]);
            save = v1[temp - 1];
        }
        for (i = temp + k - 1; i < n; i += k)
        {
            ans += (2 * v1[i]);
            save = v1[i];
        }
        ans -= save;
    }
    // cout << ans << endl;

    n = v2.size();
    if (n)
    {
        ll temp = n % k, save;
        if (temp)
        {
            ans += (2 * v2[temp - 1]);
            save = v2[temp - 1];
        }
        for (i = temp + k - 1; i < n; i += k)
        {
            ans += (2 * v2[i]);
            save = v2[i];
        }
        ans -= save;
    }
    if (!v1.empty() && !v2.empty())
    {
        ans += min(v1.back(), v2.back());
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