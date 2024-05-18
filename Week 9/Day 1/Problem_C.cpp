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
    ll n, m, i, j, num;
    cin >> n >> m;
    multiset<ll> ms1;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        ms1.insert(num);
    }
    for (i = 0; i < m; i++)
    {
        cin >> num;
        auto it = ms1.upper_bound(num);
        if (it == ms1.begin())
            cout << -1 << endl;
        else
        {
            --it;
            cout << *it << endl;
            ms1.erase(it);
        }
    }
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