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
    string a, b;
    cin >> a >> b;
    ll sz_a = a.size(), sz_b = b.size(), i, j, ans = 0;
    for (i = 0; i < sz_b; i++)
    {
        ll temp = 0;
        ll start = i;
        for (j = 0; j < sz_a && start < sz_b; j++)
        {
            if (b[start] == a[j])
            {
                start++;
                temp++;
            }
        }
        ans = max(ans, temp);
    }
    cout << sz_a + sz_b - ans << endl;
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