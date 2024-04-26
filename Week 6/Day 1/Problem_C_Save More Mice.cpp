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
    ll n, k, i, c, a;
    cin >> n >> k;
    ll A1[k + 1];
    for (i = 1; i <= k; i++)
        cin >> A1[i];
    sort(A1 + 1, A1 + k + 1);
    c = 0;
    a = 0;
    for (i = k; i > 0; i--)
    {
        if (c >= A1[i])
            break;
        else
            a++;
        c += n - A1[i];
    }
    cout << a << '\n';
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
