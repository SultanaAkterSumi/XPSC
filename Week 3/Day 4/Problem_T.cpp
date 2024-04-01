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
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i;
    cin >> n;
    vector<string> v1;
    string s1;
    set<string> st;
    for (i = 0; i < n; i++)
    {
        cin >> s1;
        v1.push_back(s1);
    }
    for (i = n - 1; i >= 0; i--)
    {
        if (st.count(v1[i]) == 0)
        {
            ll t1 = v1[i].size();
            cout << v1[i][t1 - 2] << v1[i][t1 - 1];
        }
        st.insert(v1[i]);
    }
}
int main()
{
    op() int tc = 1;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}