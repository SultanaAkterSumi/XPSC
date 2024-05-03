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
const ll MOD = 998244353;

void solve()
{
    ll i, n;
    cin >> n;
    vl v1(n), v2(n);
    set<ll> s1;
    ll temp = 0, temp1 = 1e9;
    bool f = false;
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < n; i++)
    {
        cin >> v2[i];
        if (v2[i] == 0)
        {
            temp = max(temp, v1[i] - v2[i]);
        }
        else
        {
            if (v2[i] > v1[i])
                f = true;
            s1.insert(v1[i] - v2[i]);
            temp1 = min(temp1, v1[i] - v2[i]);
        }
    }
    if (f || s1.size() > 1 || temp > temp1)
    {
        no return;
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