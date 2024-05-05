#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "Yes\n";
#define no cout << "No\n";
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
    string s1, s2;
    cin >> s1;
    s2 = s1;
    ll i, n = s1.size(), c1 = 0, c2 = 0;
    for (i = 0; i < n; i++)
    {
        if (s1[i] == '0')
            c1++;
        else
            c2++;
    }
    if (c1 == c2)
    {
        cout << 0 << endl;
        return;
    }
    ll t1 = min(c1, c2);
    ll c3 = 0, c4 = 0;
    for (i = 0; i < n; i++)
    {
        if (c3 < t1 && s1[i] == '0')
        {
            s1[i] = '1';
            c3++;
        }
        else if (c4 < t1 && s1[i] == '1')
        {
            s1[i] = '0';
            c4++;
        }
    }
    c3 = 0;
    i = 0;
    ll j = 0;
    for (; j < n;)
    {
        if (s2[i] == s1[j])
        {
            c3++;
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }
    cout << c3 << endl;
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