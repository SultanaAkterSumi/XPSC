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
const ll N = 1e5 + 1;
void solve()
{
    ll n, q1, q2, k1, k2, d1, d2;
    cin >> n >> q1 >> q2 >> k1 >> k2 >> d1 >> d2;
    bool f1;
    if ((k1 < q1 && d1 < q1) || (k1 > q1 && d1 > q1))
    {
        f1 = true;
        if ((k2 < q2 && d2 < q2) || (k2 > q2 && d2 > q2))
            f1 = true;
        else
            f1 = false;
    }
    else
        f1 = false;
    if (f1)
        yes else no
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