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
    ll n, x, num;
    cin >> n >> x;
    map<ll, ll> m1;
    while (n--)
    {
        cin >> num;
        m1[num]++;
    }
    num = 0;
    for (auto it : m1)
    {
        ll a = it.first, b = it.second, c = it.first * x;
        m1[a] = 0;
        if (m1.count(c))
        {
            if (m1[c] > b)
            {
                m1[c] -= b;
            }
            else
            {
                num += (b - m1[c]);
                m1[c] = 0;
            }
        }
        else
        {
            num += b;
        }
    }
    cout << num << endl;
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