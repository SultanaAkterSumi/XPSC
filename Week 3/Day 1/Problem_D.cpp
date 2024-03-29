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
    ll n, i, j;
    string s1;
    cin >> n;
    vector<string> v1;
    set<string> st1;
    for (i = 0; i < n; i++)
    {
        cin >> s1;
        v1.push_back(s1);
        st1.insert(s1);
    }
    string ans;
    for (i = 0; i < n; i++)
    {
        s1 = v1[i];
        ll m = s1.size();
        bool f = false;
        for (j = 1; j < m; j++)
        {
            string temp1 = s1.substr(0, j);
            string temp2 = s1.substr(j, m - j);
            if (st1.count(temp1) && st1.count(temp2))
            {
                f = true;
                break;
            }
        }
        if (f)
            ans.push_back('1');
        else
            ans.push_back('0');
    }
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