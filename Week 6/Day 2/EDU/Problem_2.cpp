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
class ass
{
public:
    ll x, y, z;
    ass(ll a, ll b, ll c)
    {
        x = a;
        y = b;
        z = c;
    }
};
void solve()
{
    ll m, n, i;
    cin >> m >> n;
    vector<ass> v1;
    for (i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v1.push_back(ass(a, b, c));
    }
    ll l = 0, r = 1e9, mid, res, c;
    while (l <= r)
    {
        mid = (l + r) / 2;
        c = 0;
        for (i = 0; i < n; i++)
        {
            ll temp1 = (v1[i].x * v1[i].y) + v1[i].z;
            ll temp2 = mid / temp1;
            c += (v1[i].y * temp2);
            if (mid % temp1)
            {
                temp2 = min(mid % temp1, (v1[i].x * v1[i].y));
                c += (temp2 / v1[i].x);
            }
        }
        if (c >= m)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res << endl;
    for (i = 0; i < n; i++)
    {
        c = 0;
        ll temp1 = (v1[i].x * v1[i].y) + v1[i].z;
        ll temp2 = res / temp1;
        c += (v1[i].y * temp2);
        if (res % temp1)
        {
            temp2 = min(res % temp1, (v1[i].x * v1[i].y));
            c += (temp2 / v1[i].x);
        }
        if (c > m)
        {
            cout << m << ' ';
            m = 0;
        }
        else
        {
            cout << c << ' ';
            m -= c;
        }
    }
}

int main()
{
    op()

        int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}
