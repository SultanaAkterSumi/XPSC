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
vector<string> v1;
void solve()
{
    ll n = v1.size();
    string s1;
    cin >> s1;
    ll cost = INT_MAX;
    ll i, j, k;
    for (i = 0; i < n; i++)
    {
        ll n1 = s1.size(), n2 = v1[i].size();
        ll temp = 0, x = 0;
        for (j = 0; j < n1; j++)
        {
            if (s1[j] == v1[i][x])
            {
                x++;
            }
            else
                temp++;
            if (x == n2)
            {
                j++;
                break;
            }
        }
        // cout << temp << endl
        //      << x << endl
        //      << j << endl;
        temp += ((n2 - x) + (n1 - j));
        cost = min(cost, temp);
        // cout << temp << endl;
    }
    cout << cost << endl;
}
int main()
{
    op() int tc = 1;
    // Sieve();
    ll temp1 = 1;
    ll temp2 = 1e18;
    while (temp1 <= temp2)
    {
        string s1 = to_string(temp1);
        v1.push_back(s1);
        temp1 *= 2;
    }
    // for (auto it : v1)
    //     cout << it << endl;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}
