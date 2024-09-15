#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;
vl v1(N), v2(N);
void solve()
{
    ll n;
    cin >> n;
    if (n % 2 == 0)
    {
        no return;
    }
    vl v1(n + 1);
    ll i = n + 1, j;
    for (j = n; j >= 1; j -= 2)
    {
        v1[j] = i;
        i++;
    }
    for (j = n - 1; j >= 1; j -= 2)
    {
        v1[j] = i;
        i++;
    }
    yes for (i = 1; i <= n; i++) cout << i << ' ' << v1[i] << endl;
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}