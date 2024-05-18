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
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}
void solve()
{
    ll n, i, num;
    map<ll, ll> m1;
    cin >> n;
    while (n--)
    {
        cin >> num;
        m1[num]++;
    }
    vector<ll> v1;
    set<ll> s1;
    for (auto it : m1)
    {
        if (it.second == 1)
            v1.push_back(it.first);
        else
            s1.insert(it.first);
    }
    sort(v1.begin(), v1.end());
    ll t1 = 1;
    for (auto it : v1)
    {
        if (t1 % 2)
            s1.insert(it);
        t1++;
    }
    t1 = 0;
    for (auto it : s1)
    {
        if (it != t1)
        {
            cout << t1 << endl;
            return;
        }
        t1++;
    }
    cout << t1 << endl;
}
int main()
{
    op() int tc = 1;
    // Sieve();
    cin >> tc;
    // cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case "<<t<<": ";
        // cout<<"Scenario #"<<t<<": ";
        solve();
    }
}