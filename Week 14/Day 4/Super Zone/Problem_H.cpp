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
const ll N = 1e6 + 1;
void solve()
{
    ll n, i;
    cin >> n;
    vl v1(n), v2(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        v2[i] = v1[i];
    }
    sort(v2.begin(), v2.end());
    if (v1 == v2)
    {
        cout << 0 << endl;
        return;
    }

    ll c = 1, Min = v1[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        if (v1[i] <= v1[i + 1])
        {
            c++;
            Min = v1[i];
        }
        else
            break;
    }
    ll save = v1[i];
    i--;
    for (; i >= 0; i--)
    {
        if (v1[i] < save && v1[i] <= Min)
        {
            cout << -1 << endl;
            return;
        }
    }

    cout << n - c << endl;
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