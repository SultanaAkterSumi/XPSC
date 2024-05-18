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
    ll r, c;
    cin >> r >> c;

    ll t2 = ((1 + 2 * (r - 1)) / 2) + 1;
    if (t2 >= c)
    {
        ll t1 = 1 + (r * (r - 1));
        if (r % 2)
            t1 -= (t2 - c);
        else
            t1 += (t2 - c);
        cout << t1 << endl;
    }
    else
    {
        ll t1 = 1 + (c * (c - 1));
        if (c % 2)
            t1 += (c - r);
        else
            t1 -= (c - r);
        cout << t1 << endl;
    }
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