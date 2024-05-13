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
    ll n, i, num, j;
    cin >> n;
    map<ll, ll> m1;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        ll temp = sqrt(num);
        for (j = 2; j <= temp && num > 1; j++)
        {
            while (num % j == 0)
            {
                m1[j]++;
                num /= j;
            }
        }
        if (num > 1)
            m1[num]++;
    }

    for (auto it : m1)
    {
        // cout << it.first << ' ' << it.second << endl;
        if (it.second % n)
        {
            no return;
        }
    }
    yes
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