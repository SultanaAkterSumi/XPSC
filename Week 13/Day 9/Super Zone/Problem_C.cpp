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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e6 + 1;

void solve()
{
    ll n, k, ans = 0, i;
    cin >> n >> k;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        ans += (v1[i] / k);
        v1[i] %= k;
    }
    sort(v1.rbegin(), v1.rend());
    i = 0;
    ll j = n - 1;
    while (i < j)
    {
        while (i < j && (v1[i] + v1[j]) / k == 0)
            j--;
        if (i == j)
            break;
        ans++;
        i++;
        j--;
    }
    cout << ans << endl;
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