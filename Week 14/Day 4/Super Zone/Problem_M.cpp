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
bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    if (a.first != b.first)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}
void solve()
{
    ll n, num, i, j;
    cin >> n;
    vl v1(10);
    for (i = 0; i < n; i++)
    {
        cin >> num;
        v1[num % 10]++;
    }

    for (i = 0; i <= 9; i++)
    {
        for (j = 0; j <= 9; j++)
        {
            ll t = 3 - (i + j);

            while (t < 0)
                t += 10;

            if (v1[i])
            {

                v1[i]--;
                if (v1[j])
                {
                    v1[j]--;
                    if (v1[t])
                    {
                        // cout << i << ' ' << j << ' ' << t << endl;
                        yes return;
                    }
                    else
                    {
                        v1[i]++;
                        v1[j]++;
                    }
                }
                else
                    v1[i]++;
            }
        }
    }

    no
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