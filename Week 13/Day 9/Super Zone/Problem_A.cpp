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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e6 + 1;

void solve()
{
    ll c, d, n, i;
    cin >> n >> c >> d;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    sort(v1.rbegin(), v1.rend());
    ll sum = 0, m = min(n, d);
    for (i = 0; i < m; i++)
        sum += v1[i];
    if (sum >= c)
    {
        cout << "Infinity\n";
        return;
    }
    if (v1[0] * d < c)
    {
        cout << "Impossible\n";
        return;
    }
    ll l = 0, r = d - 2, mid, res = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        ll temp = 0, days = d;
        m = min(n, mid + 1);
        for (i = 0; i < m; i++)
        {
            days--;
            if (days < 0)
                break;
            temp += (v1[i] + v1[i] * (days / (mid + 1)));
        }
        if (temp >= c)
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
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}