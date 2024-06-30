#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "yes\n";
#define no cout << "no\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 1e3 + 1;
const ll MOD = 1e9 + 7;
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}
ll fun(ll b, ll p, ll m)
{
    if (p == 0)
        return 1;

    if (p % 2 == 0)
    {
        ll ans = fun(b, p / 2, m);
        if (ans > m)
            return 0;
        ll ans1 = ans * ans;
        if (ans1 > m)
            return 0;
        return ans1;
    }
    else
    {
        ll ans = fun(b, p / 2, m);
        if (ans > m)
            return 0;
        ll ans1 = ans * ans;
        if (ans1 > m)
            return 0;
        ans1 *= b;
        if (ans1 > m)
            return 0;
        return ans1;
    }
}
void solve()
{
    ll n, k, i, num;
    cin >> n >> k;
    vl v1(31);
    for (i = 0; i < n; i++)
    {
        cin >> num;
        ll j = 0;
        while (num)
        {
            if (num & 1)
                v1[j]++;
            j++;
            num = num >> 1;
        }
    }
    ll ans = 0;
    for (i = 30; i >= 0; i--)
    {
        if (n - v1[i] <= k)
        {
            ans += (1 << i);
            k -= (n - v1[i]);
        }
    }
    cout << ans << endl;
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}