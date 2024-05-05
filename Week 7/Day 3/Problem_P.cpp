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
    ll i, n = s1.size(), b = 0, B = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (s1[i] == 'b')
            b++;
        else if (s1[i] == 'B')
            B++;
        else
        {
            if (s1[i] >= 'a' && s1[i] <= 'z')
            {
                if (b)
                    b--;
                else
                    s2.push_back(s1[i]);
            }
            else if (s1[i] >= 'A' && s1[i] <= 'Z')
            {
                if (B)
                    B--;
                else
                    s2.push_back(s1[i]);
            }
        }
    }
    reverse(s2.begin(), s2.end());
    cout << s2 << endl;
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