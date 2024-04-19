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
    ll n, i;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    sort(v1.begin(), v1.end());
    ll q, a, b;
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        ll l = 0, r = n - 1, mid, res1 = -1, res2 = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v1[mid] < a)
                l = mid + 1;
            else
            {
                res1 = mid;
                r = mid - 1;
            }
        }
        l = 0;
        r = n - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v1[mid] > b)
                r = mid - 1;
            else
            {
                res2 = mid;
                l = mid + 1;
            }
        }
        if (res1 == -1 || res2 == -1)
            cout << 0 << ' ';
        else
            cout << res2 - res1 + 1 << ' ';
    }
    cout << endl;
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
