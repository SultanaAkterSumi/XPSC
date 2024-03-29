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
    cin >> n;
    vector<vl> v1(n, vl(n - 1));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
            cin >> v1[i][j];
    }
    map<ll, ll> m1;
    vl ans;
    for (i = 0; i < n; i++)
    {
        m1[v1[i][0]]++;
    }
    ll temp;
    for (auto it : m1)
    {
        if (it.second == n - 1)
            ans.push_back(it.first);
        else
            temp = it.first;
    }

    for (i = 1; i < n - 1; i++)
    {
        set<ll> s1;
        for (j = 0; j < n; j++)
        {
            s1.insert(v1[j][i]);
        }
        s1.erase(temp);
        ans.push_back(temp);
        temp = *s1.begin();
    }
    ans.push_back(temp);
    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
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