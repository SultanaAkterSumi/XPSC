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
vl v1;
ll n, l, r, x, ans = 0;
void fun(ll i, ll low, ll sum, ll c)
{

    ll j;
    for (j = i + 1; j < n; j++)
    {

        fun(j, low, sum + v1[j], c + 1);
    }
    // cout << sum << ' ' << v1[i] << ' ' << c << endl;
    if (sum >= l && sum <= r && v1[i] - low >= x && c >= 2)
        ans++;
}
void solve()
{
    ll i, num;
    cin >> n >> l >> r >> x;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        v1.push_back(num);
    }
    sort(v1.begin(), v1.end());

    for (i = 0; i < n - 1; i++)
    {
        fun(i, v1[i], v1[i], 1LL);
    }
    cout << ans << endl;
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
