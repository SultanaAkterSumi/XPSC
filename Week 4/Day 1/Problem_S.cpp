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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;
vl v1;
ll n;
bool fun(ll i, ll sum)
{
    // cout << i << ' ' << sum << endl;
    if (i == n)
    {
        if (sum % 360 == 0)
            return true;
        return false;
    }
    return (fun(i + 1, sum + v1[i]) || fun(i + 1, sum - v1[i]));
}
void solve()
{
    ll num, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        v1.push_back(num);
    }
    if (fun(0, 0))
        yes else no
}
int main()
{
    op()

        int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}