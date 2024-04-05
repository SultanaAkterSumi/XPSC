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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, i;
    string s1;
    cin >> n >> s1;
    ll c = 0;
    for (i = 0; i < (n / 2); i++)
    {
        if (s1[i] != s1[n - i - 1])
            c++;
    }
    for (i = 0; i < c; i++)
        cout << 0;
    cout << 1;
    if (n % 2)
    {
        for (i = c + 1; i <= n; i++)
        {
            ll t1 = i - c;
            if (t1 % 2)
                t1--;
            ll t2 = n - (2 * c) - 1;
            if (t2 < t1)
                cout << 0;
            else
                cout << 1;
        }
    }
    else
    {
        for (i = c + 1; i <= n; i++)
        {
            ll t1 = i - c;
            if (t1 % 2)
            {
                cout << 0;
                continue;
            }
            ll t2 = n - (2 * c);
            if (t2 < t1)
                cout << 0;
            else
                cout << 1;
        }
    }
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