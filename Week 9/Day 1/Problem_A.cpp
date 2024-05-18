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
    ll n, i, j = 0, ans = 0, temp = 0;
    cin >> n;
    vl v1(n);
    map<ll, ll> m1;
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        if (m1[v1[i]] == 0)
        {
            m1[v1[i]]++;
            temp++;
            ans = max(ans, temp);
        }
        else
        {
            while (v1[j] != v1[i])
            {
                m1[v1[j]] = 0;
                j++;
            }
            temp = i - j;
            j++;
        }
    }
    cout << ans;
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