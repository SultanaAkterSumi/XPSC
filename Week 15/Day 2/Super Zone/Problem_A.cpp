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
    ll n, m, a, i;
    cin >> n;
    if (n == 3)
    {
        cout << "1 3 2\n";
        return;
    }
    vl v1(n);
    if (n & 1)
    {
        v1[0] = 0;
        a = 1;
        for (i = 1; i < n; i += 2)
        {
            v1[i] = a;
            a++;
        }
        for (i = 2; i < n; i += 2)
            v1[i] = ((1 << 20) | v1[i - 1]);
        if (((n - 1) / 2) & 1)
        {
            v1[n - 1] = ((v1[n - 1] & ((1 << 20) - 1)) | 1 << 21);
            v1[n - 3] = (v1[n - 3] | 1 << 21);
        }
    }
    else
    {
        a = 1;
        for (i = 0; i < n; i += 2)
        {
            v1[i] = a;
            a++;
        }
        for (i = 1; i < n; i += 2)
            v1[i] = ((1 << 20) | v1[i - 1]);
        if ((n / 2) & 1)
        {
            v1[n - 1] = ((v1[n - 1] & ((1 << 20) - 1)) | 1 << 21);
            v1[n - 3] = (v1[n - 3] | 1 << 21);
        }
    }
    for (i = 0; i < n; i++)
        cout << v1[i] << ' ';
    cout << endl;
    // ll temp1 = 0;
    // for (i = 0; i < n; i += 2)
    //     temp1 ^= v1[i];
    // ll temp2 = 0;
    // for (i = 1; i < n; i += 2)
    //     temp2 ^= v1[i];
    // cout << temp1 << ' ' << temp2 << endl;
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