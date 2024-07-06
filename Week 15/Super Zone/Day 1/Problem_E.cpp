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
    ll n;
    cin >> n;
    if (n == 1)
        cout << 1 << endl;
    else if (n % 2)
        cout << -1 << endl;
    else
    {
        ll i, j, m, temp;
        vector<pair<ll, ll>> v1;
        v1.push_back({0, n});
        v1.push_back({n - 1, n - 1});
        i = 1;
        j = n - 2;
        temp = n + n - 1;
        m = (n / 2) - 1;
        while (m--)
        {
            v1.push_back({i, (n - v1.back().first + i)});
            v1.push_back({j, (j - i)});
            i++;
            j--;
        }
        for (auto it : v1)
            cout << it.second << ' ';
        cout << endl;
    }
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