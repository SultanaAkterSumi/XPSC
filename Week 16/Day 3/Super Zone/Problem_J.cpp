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
const ll N = 1e9 + 7;

void solve()
{
    ll n, m, k;
    string s1;
    cin >> n >> m >> k >> s1;
    s1.push_back('L');
    ll i = 0, w1 = 0;
    while (i <= n)
    {
        if (s1[i] == 'L')
            i++;
        else if (s1[i] == 'W')
        {
            ll j = i, c = -1, w2;
            while (j <= n)
            {
                if (s1[j] == 'L')
                    break;
                else if (s1[j] == 'W')
                    w2++;
                else
                    c = j;
                j++;
            }
            ll t1 = min(i - 1 + m, j);
            if (t1 > c)
            {
                ll t1 = min(i - 1 + m, j);
                i = j;
                w1 += (j - t1);
            }
            else
            {
                no return;
            }
        }
        else
        {
            ll j = i;
            while (j <= n)
            {
                if (s1[j] == 'L')
                    break;
                j++;
            }
            ll safe = j;
            while (1)
            {
                if (s1[safe] == 'C')
                    break;
                safe--;
            }
            safe++;
            if (i - 1 + m < safe)
            {
                no return;
            }
            ll t1 = min(i - 1 + m, j);

            i = j;
            w1 += (j - t1);
        }
    }
    if (w1 > k)
        no else yes
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