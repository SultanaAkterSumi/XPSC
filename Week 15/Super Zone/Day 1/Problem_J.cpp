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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e6 + 1;
bool is_vowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;
    else
        return false;
}
void solve()
{
    string s, t;
    cin >> s >> t;
    ll i, n1 = s.size(), n2 = t.size();
    if (n1 == n2)
    {
        for (i = 0; i < n1; i++)
        {
            if (is_vowel(s[i]))
            {
                if (!is_vowel(t[i]))
                {
                    cout << "No";
                    return;
                }
            }
            else
            {
                if (is_vowel(t[i]))
                {
                    cout << "No";
                    return;
                }
            }
        }
        cout << "Yes";
    }
    else
        cout << "No";
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