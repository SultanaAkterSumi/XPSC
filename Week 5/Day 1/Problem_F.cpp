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
    ll n, i;
    cin >> n;
    vl v1(n), v2(30);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        ll j = 0;
        while (v1[i])
        {
            if (1 & v1[i])
                v2[j]++;
            v1[i] = v1[i] >> 1;
            j++;
        }
    }
    ll GCD;
    for (i = 0; i < 30; i++)
        if (v2[i])
        {
            GCD = v2[i];
            break;
        }
    if (i == 30)
    {
        for (i = 1; i <= n; i++)
            cout << i << ' ';
        cout << endl;
        return;
    }
    for (; i < 30; i++)
    {
        GCD = gcd(GCD, v2[i]);
    }
    vl ans;
    ll t = sqrt(GCD);
    for (i = 1; i <= t; i++)
    {
        if (GCD % i == 0)
        {
            ans.push_back(i);
            if (i != GCD / i)
                ans.push_back(GCD / i);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
        cout << it << ' ';
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
