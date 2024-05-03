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
const ll MOD = 998244353;

void solve()
{
    ll n, i, j, c, ans = -1;
    string s1;
    cin >> n >> s1;
    set<char> st1;
    for (auto it : s1)
    {
        st1.insert(it);
    }
    bool pos = true;
    for (i = 0; i <= n / 2; i++)
    {
        if (s1[i] != s1[n - i - 1])
        {
            pos = false;
            break;
        }
    }
    if (pos)
    {
        cout << 0 << endl;
        return;
    }
    for (auto it : st1)
    {
        i = 0;
        j = n - 1;
        c = 0;
        pos = true;
        while (i <= j)
        {
            if (s1[i] == s1[j])
            {
                i++;
                j--;
            }
            else if (s1[i] == it)
            {
                i++;
                c++;
                continue;
            }
            else if (s1[j] == it)
            {
                j--;
                c++;
                continue;
            }
            else if (s1[i] != s1[j])
            {
                pos = false;
                break;
            }
        }
        if (pos)
        {
            if (ans == -1)
                ans = c;
            else
                ans = min(ans, c);
        }
    }
    cout << ans << endl;
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