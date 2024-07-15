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
const ll N = 1e5 + 1;
void solve()
{
    ll n, i, x, y;
    cin >> n;
    vl v1;
    cin >> x;
    set<ll> s1;
    for (i = 1; i <= n; i++)
        s1.insert(i);
    if (x <= n)
        s1.erase(x);
    else
        v1.push_back(x);
    for (i = 2; i < n; i++)
    {
        cin >> y;
        if (y - x <= n && s1.find(y - x) != s1.end())
            s1.erase(y - x);
        else
            v1.push_back(y - x);
        x = y;
    }
    bool f1 = true;
    if (s1.size() > 1)
    {
        ll temp1 = 0, temp2 = 0;
        for (auto it : v1)
            temp1 += it;
        for (auto it : s1)
            temp2 += it;
        if (temp1 != temp2 || v1.size() > 1)
            f1 = false;
    }
    if (f1)
        yes else no
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