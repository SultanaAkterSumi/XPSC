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
    ll n, k, d, w, j, i, temp, c = 0;
    cin >> n >> k >> d >> w;
    vl v1(n);
    bool flag = false;
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        if (flag == false)
        {
            j = i;
            c++;
            temp = k - 1;
            if (temp)
                flag = true;
            else
                flag = false;
        }
        else
        {
            if ((v1[i] - v1[j] - w) <= d)
            {
                temp--;
                if (temp == 0)
                    flag = false;
            }
            else
            {
                j = i;
                c++;
                temp = k - 1;
                if (temp)
                    flag = true;
                else
                    flag = false;
            }
        }
    }
    cout << c << endl;
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