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

void solve()
{
    ll n, j, sum = 0;
    cin >> n;
    vl v1(n);
    for (j = 0; j < n; j++)
    {
        cin >> v1[j];
        sum += abs(v1[j]);
    }
    sum = sum / 2;
    ll i = sum, d = sum, pi = 0, pd = 0, cost = 0;
    // cout << sum << endl;
    for (j = 0; j < n; j++)
    {
        if (v1[j] < 0)
        {
            if (pi >= abs(v1[j]))
                pi -= abs(v1[j]);
            else
            {
                pd += (abs(v1[j]) - pi);
                i -= (abs(v1[j]) - pi);
                d -= (abs(v1[j]) - pi);
                cost += (abs(v1[j]) - pi);
                pi = 0;
            }
        }
        else if (v1[j] > 0)
        {
            if (d >= v1[j])
            {
                d -= v1[j];
                pi += v1[j];
            }
            else
            {
                i -= d;
                pi += d;
                pd -= (v1[j] - d);
                d = 0;
            }
        }
    }
    cout << cost << endl;
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
