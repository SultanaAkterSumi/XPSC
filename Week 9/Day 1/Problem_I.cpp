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
const ll MOD = 1e9 + 7;
void solve()
{
    ll n, x, i;
    cin >> n >> x;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    ll ans = 0, sum = 0, j = 0;
    for (i = 0; i < n; i++)
    {
        // cout<<sum<<endl;
        if (sum + v1[i] == x)
        {
            ans++;
            sum = sum + v1[i] - v1[j];
            j++;
        }
        else if (sum + v1[i] > x)
        {
            sum = sum - v1[j];
            j++;
            i--;
        }
        else
            sum += v1[i];
    }
    cout << ans;
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