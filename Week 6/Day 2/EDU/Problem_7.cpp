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
    ll n, k, l = 1, r, mid, res, i;
    cin >> n >> k;
    vl v1(n + 1);
    for (i = 1; i <= n; i++)
    {
        cin >> v1[i];
    }
    r = v1[n] - v1[0];

    while (l <= r)
    {
        mid = (l + r) / 2;
        ll c = 1, next = v1[1] + mid;
        i = 2;
        while (i <= n && c < k)
        {
            if (v1[i] >= next)
            {
                c++;
                next = v1[i] + mid;
            }
            i++;
        }
        if (c == k)
        {
            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << res << endl;
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
