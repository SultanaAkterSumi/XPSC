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
    ll n, i, k, ans;
    cin >> n >> k;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    sort(v1.begin(), v1.end());
    ll mid = v1[n / 2];
    i = (n / 2);
    ll c = 0;
    while (1)
    {
        while (i < n && v1[i] == mid)
        {
            i++;
            c++;
        }

        if (i < n)
        {
            ll diff;
            diff = v1[i] - mid;
            ll temp = c * diff;
            if (c * diff <= k)
            {
                mid += diff;
                k -= (c * diff);
            }
            else
            {
                ll temp = k / c;
                cout << mid + temp;
                return;
            }
        }
        else
        {
            ll temp = k / c;
            cout << mid + temp;
            return;
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
