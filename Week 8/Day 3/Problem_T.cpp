#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 1e5 + 1;
const ll MOD = 998244353;

void solve()
{
    ll l, r, i, t1;
    cin >> l >> r;
    if (r <= 3)
        cout << -1 << endl;
    else if (l == r)
    {
        if (l % 2)
        {
            ll t1 = sqrt(l);
            bool f1 = false;
            for (i = 3; i <= t1; i++)
            {
                if (gcd(i, l - i) != 1)
                {
                    f1 = true;
                    break;
                }
            }
            if (f1)
                cout << i << ' ' << l - i << endl;
            else
                cout << -1 << endl;
        }
        else
            cout << 2 << ' ' << l - 2 << endl;
    }
    else
    {
        if (r % 2)
            cout << 2 << ' ' << r - 3 << endl;
        else
            cout << 2 << ' ' << r - 2 << endl;
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