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

void solve()
{
    ll n, i, k, c = 0, num;
    cin >> n >> k;
    vl v1;
    while (n--)
    {
        cin >> num;
        // cout << (num & k) << endl;
        if ((num & k) == k)
            v1.push_back(num);
    }
    if (v1.empty())
    {
        no return;
    }
    ll m = v1.size();
    ll ans = v1[0];
    for (i = 1; i < m; i++)
        ans = (ans & v1[i]);
    if (ans == k)
        yes else no
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}