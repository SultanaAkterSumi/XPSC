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
vl v1(10001);
void solve()
{
    ll n, i;
    cin >> n;
    bool f1 = false;
    for (i = 1; i <= 10000; i++)
    {
        if (i * i * i >= n)
            break;
        ll t1 = i * i * i;
        t1 = n - t1;
        ll l = 1, h = 10000;
        while (l <= h)
        {
            ll mid = (l + h) / 2;
            if (v1[mid] == t1)
            {
                f1 = true;
                break;
            }
            else if (v1[mid] > t1)
                h = mid - 1;
            else
                l = mid + 1;
        }
        if (f1)
            break;
    }
    if (f1)
        yes else no
}

int main()
{
    op()
        ll i;
    for (i = 1; i <= 10000; i++)
        v1[i] = i * i * i;
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}
