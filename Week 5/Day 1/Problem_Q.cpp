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
    string s1;
    cin >> s1;
    ll n, i;
    map<char, ll> m1;
    n = s1.size();
    for (i = 0; i < n; i++)
        m1[s1[i]]++;
    if (n % 2)
    {
        if (m1.size() == 1)
            no else if (m1.size() == 2)
            {
                for (auto it : m1)
                {
                    if (it.second == 1)
                    {
                        no return;
                    }
                }
                yes
            }
        else
            yes
    }
    else
    {
        if (m1.size() == 1)
            no else yes
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
