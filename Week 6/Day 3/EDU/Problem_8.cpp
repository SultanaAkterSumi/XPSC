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
    ll n, k, i;
    cin >> n >> k;
    vl v1(n), v2(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (i = 0; i < n; i++)
    {
        cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll l = v1[0] + v2[0], r = v1[n - 1] + v2[n - 1], mid, res;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // cout << mid << endl;
        ll c1 = 0, c2 = 0; // c2->mid;
        for (i = 0; i < n; i++)
        {
            if (v1[i] >= mid)
                break;
            ll temp = mid - v1[i];
            ll l1 = 0, r1 = n - 1, mid1, res1 = -1;
            while (l1 <= r1)
            {
                mid1 = (l1 + r1) / 2;
                if (v2[mid1] <= temp)
                {
                    res1 = mid1;
                    l1 = mid1 + 1;
                }
                else
                    r1 = mid1 - 1;
            }

            ll l2 = 0, r2 = n - 1, mid2, res2 = -1;
            while (l2 <= r2)
            {
                mid2 = (l2 + r2) / 2;
                if (v2[mid2] < temp)
                {
                    res2 = mid2;
                    l2 = mid2 + 1;
                }
                else
                    r2 = mid2 - 1;
            }
            if (res1 == -1)
                continue;
            else if (res2 == -1)
                c2 += (res1 + 1);
            else
            {
                c1 += (res2 + 1);
                c2 += (res1 - res2);
            }
        }
        if (c1 + c2 >= k)
        {
            if (c2)
            {
                if (c1 >= k)
                    r = mid - 1;
                else
                {
                    cout << mid << endl;
                    return;
                }
            }
            else
                r = mid - 1;
        }
        else
            l = mid + 1;
    }
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
