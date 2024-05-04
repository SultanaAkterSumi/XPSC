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
const ll MOD = 1e9 + 7;

void solve()
{
    ll q, x;
    bool f;
    vl v1;
    cin >> q;
    f = 1;
    while (q--)
    {
        cin >> x;
        if (v1.size() == 0)
        {
            v1.push_back(x);
            cout << 1;
        }
        else
        {
            if (f)
            {
                if (x >= v1.back())
                {
                    v1.push_back(x);
                    cout << 1;
                }
                else if (x <= v1.front())
                {
                    v1.push_back(x);
                    cout << 1;
                    f = 0;
                }
                else
                    cout << 0;
            }
            else
            {
                if (x >= v1.back() && x <= v1.front())
                {
                    v1.push_back(x);
                    cout << 1;
                }
                else
                    cout << 0;
            }
        }
    }
    cout << endl;
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