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

void solve()
{
    ll n, i, a = 0, b = 0, ans1 = 0, ans2 = 0;
    cin >> n;
    vl v1(n), v2(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < n; i++)
        cin >> v2[i];
    for (i = 0; i < n; i++)
    {
        if (v1[i] == -1 && v2[i] == -1)
        {
            b++;
        }
        else if (v1[i] == 1 && v2[i] == 1)
        {
            a++;
        }
        else
        {
            if (v1[i] > v2[i])
                ans1 += v1[i];
            else
                ans2 += v2[i];
        }
    }
    while (a || b)
    {
        if (a)
        {
            if (ans1 < ans2)
                ans1++;
            else
                ans2++;
            a--;
        }
        if (b)
        {
            if (ans1 < ans2)
                ans2--;
            else
                ans1--;
            b--;
        }
    }
    cout << min(ans1, ans2) << endl;
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