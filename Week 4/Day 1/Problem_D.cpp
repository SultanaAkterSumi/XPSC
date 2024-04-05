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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, m = 0, num;
    ;
    cin >> n;
    ll c = 0;
    while (n--)
    {
        cin >> num;
        if (num)
        {
            m = (m ^ num);
        }
        c++;
    }
    if (c % 2)
    {
        cout << m << endl;
    }
    else
    {
        if (m == 0)
            cout << m << endl;
        else
            cout << -1 << endl;
    }
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