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
    ll n, i, j;
    cin >> n;
    vl v1(1001, -1), v2(n);
    vector<bool> v3(1001, false);
    for (i = 0; i < n; i++)
    {
        cin >> v2[i];
        v3[v2[i]] = true;
    }
    // for (i = 4; i <= 1000; i++)
    // {
    //     if (v3[i])
    //         cout << i << endl;
    // }
    ll c = 1;
    for (i = 2; i <= 1000; i++)
    {
        if (v1[i] == -1)
        {
            ll c1 = 0;
            for (j = i; j <= 1000; j += i)
            {
                if (v1[j] == -1)
                {
                    v1[j] = c;
                    if (v3[j])
                    {
                        c1++;
                        v3[j] = false;
                    }
                }
            }
            if (c1)
                c++;
        }
    }
    cout << c - 1 << endl;
    for (i = 0; i < n; i++)
    {
        cout << v1[v2[i]] << ' ';
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