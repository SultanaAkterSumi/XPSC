#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define gcd(a, b) __gcd(a, b)
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, num, ans = 0, i;
    cin >> n;
    map<ll, ll> m1;
    while (n--)
    {
        cin >> num;
        m1[num]++;
    }
    vector<pair<ll, ll>> v1;
    for (auto it : m1)
    {
        v1.push_back({it.first, it.second});
    }
    ll t1 = v1[0].first, t2 = v1[0].second;
    n = v1.size();
    for (i = 1; i < n; i++)
    {
        if (v1[i].first == t1 + 1)
        {
            if (t2 > v1[i].second)
                ans += (t2 - v1[i].second);
        }
        else
            ans += t2;
        t1 = v1[i].first;
        t2 = v1[i].second;
    }
    ans += t2;
    cout << ans << endl;
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