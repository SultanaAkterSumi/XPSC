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
const ll N = 2e5 + 1;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, k, q, i, num;
    cin >> n >> k >> q;
    vl v1, v2, v3;
    v1.push_back(0);
    v2.push_back(0);
    v3.push_back(0);
    for (i = 0; i < k; i++)
    {
        cin >> num;
        v1.push_back(num);
    }
    for (i = 0; i < k; i++)
    {
        cin >> num;
        v2.push_back(num);
        v3.push_back(num + v3.back());
    }
    ll m = k + 1;
    while (q--)
    {
        cin >> num;
        ll ans;
        ll l = 0, r = k, mid, res1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v1[mid] == num)
            {
                res1 = mid;
                break;
            }
            else if (v1[mid] < num)
            {
                res1 = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        ans = v2[res1];
        if (v1[res1] == num)
        {
            cout << ans << ' ';
            continue;
        }
        ll t1 = v1[res1 + 1] - v1[res1];
        ll t2 = v2[res1 + 1] - v2[res1];
        ll t3 = num - v1[res1];
        cout << ans + (t2 * t3) / t1 << ' ';
    }
    cout << endl;
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