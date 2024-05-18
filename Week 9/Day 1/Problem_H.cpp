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
const ll MOD = 1e9 + 7;
void solve()
{
    string s1, s2;
    cin >> s1;
    s2 = s1;
    vector<int> v1(26);
    ll n = s1.size(), i;
    for (i = 0; i < n; i++)
    {
        v1[s1[i] - 'A']++;
    }
    bool f = true;
    if (n % 2)
        f = false;
    ll left = 0, right = n - 1;
    for (i = 0; i < 26; i++)
    {

        char ch = i + 'A';
        if (v1[i] % 2)
        {
            if (f)
            {
                cout << "NO SOLUTION\n";
                return;
            }
            s2[n / 2] = ch;
            f = true;
        }
        ll temp = v1[i] / 2;
        while (temp--)
        {
            s2[left] = ch;
            left++;
        }
        temp = v1[i] / 2;
        while (temp--)
        {
            s2[right] = ch;
            right--;
        }
    }
    cout << s2 << endl;
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