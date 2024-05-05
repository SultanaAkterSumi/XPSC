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
    ll n, i, n0 = 0, n1 = 0, inv = 0, first0 = -1, last1 = -1;
    cin >> n;
    vl v1(n);
    bool f = true;
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = n - 1; i >= 0; i--)
    {
        if (v1[i] == 1)
        {
            n1++;
            inv += n0;
            if (f)
            {
                last1 = i;
                f = false;
            }
        }
        else
        {
            n0++;
            first0 = i;
        }
    }
    ll t1 = inv + n0 - 1 - first0;
    ll t2 = inv + n1 + last1 - n;
    inv = max({inv, t1, t2});
    cout << inv << endl;
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