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

ll fact(ll n)
{
    if (n <= 1)
        return 1;
    return ((n % MOD) * (fact(n - 1) % MOD)) % MOD;
}
void solve()
{
    ll n, k, i, j;
    cin >> n >> k;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    if (k >= 3)
    {
        cout << 0 << endl;
        return;
    }
    sort(v1.begin(), v1.end());
    if (k == 1)
    {
        ll ans = v1[0];
        for (i = 1; i < n; i++)
        {
            ans = min(v1[i], ans);
            ans = min(v1[i] - v1[i - 1], ans);
        }
        cout << ans << endl;
        return;
    }
    if (k == 2)
    {
        ll ans = v1[0];
        set<ll> s1;
        for (i = 1; i < n; i++)
        {
            ans = min(v1[i], ans);
            ans = min(v1[i] - v1[i - 1], ans);
        }
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                s1.insert(v1[j] - v1[i]);
            }
        }
        for (auto it : s1)
        {
            // upper & lower bound
            ll l = 0, r = n - 1, mid, res = -1;

            while (l <= r)
            {
                mid = (l + r) / 2;
                if (v1[mid] > it)
                    r = mid - 1;
                else
                {
                    res = v1[mid];
                    l = mid + 1;
                }
            }
            if (res != -1)
                ans = min(ans, it - res);

            l = 0;
            r = n - 1;
            res = -1;

            while (l <= r)
            {
                mid = (l + r) / 2;
                if (v1[mid] < it)
                    l = mid + 1;
                else
                {
                    res = v1[mid];
                    r = mid - 1;
                }
            }
            if (res != -1)
                ans = min(ans, res - it);
        }
        cout << ans << endl;
        return;
    }
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