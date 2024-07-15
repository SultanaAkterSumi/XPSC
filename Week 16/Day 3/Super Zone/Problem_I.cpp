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
const ll N = 2e5 + 1;

void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n), v2(n);
    vector<bool> vis(N, false);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < n; i++)
        cin >> v2[i];

    map<ll, ll> m1;
    for (i = 0; i < n; i++)
    {
        m1[v1[i]] = v2[i];
    }
    ll len, j;
    ll ev = 0;
    for (i = 0; i < n; i++)
    {
        if (!vis[v1[i]])
        {

            len = 1;
            j = v1[i];
            while (j && v1[i] != m1[j])
            {

                vis[j] = true;
                j = m1[j];
                len++;
            }
            if (j == 0)
            {
                no return;
            }
            vis[j] = true;
            if (len % 2 == 0)
                ev++;
        }
    }

    if (ev % 2 == 0)
        yes else no
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