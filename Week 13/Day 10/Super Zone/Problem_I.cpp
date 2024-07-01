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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e6 + 1;
bool cmp(pair<pair<ll, ll>, ll> a, pair<pair<ll, ll>, ll> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first.first < b.first.first;
}
void solve()
{
    string s1;
    cin >> s1;
    ll l = 0, r = 0, u = 0, d = 0, i;
    for (auto it : s1)
    {
        if (it == 'L')
            l++;
        else if (it == 'R')
            r++;
        else if (it == 'U')
            u++;
        else
            d++;
    }
    ll a = min(l, r), b = min(u, d);
    if (a == 0 && b == 0)
    {
        cout << 0 << endl;
    }
    else if (!a && b)
    {
        cout << 2 << endl
             << "DU" << endl;
    }
    else if (a && !b)
    {
        cout << 2 << endl
             << "LR" << endl;
    }
    else
    {
        cout << 2 * a + 2 * b << endl;
        for (i = 0; i < a / 2; i++)
        {
            cout << 'R';
        }
        for (i = 0; i < b; i++)
        {
            cout << 'D';
        }
        for (i = 0; i < a; i++)
        {
            cout << 'L';
        }
        for (i = 0; i < b; i++)
        {
            cout << 'U';
        }

        for (i = 0; i < a - (a / 2); i++)
        {
            cout << 'R';
        }
        cout << endl;
    }
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