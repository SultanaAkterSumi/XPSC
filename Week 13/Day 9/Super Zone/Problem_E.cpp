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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;

const ll INF = 300001;
void solve()
{
    ll n;
    cin >> n;
    if (n % 32768 == 0)
    {
        cout << 0 << endl;
        return;
    }
    vl v1(16);
    ll m = n, i = 0;
    while (m)
    {
        if (m % 2)
            v1[i] = 1;
        m /= 2;
        i++;
    }
    i = 0;
    while (v1[i] == 0)
    {
        i++;
    }
    ll ans = 15 - i;
    // cout << ans << endl;
    i = 0;
    ll temp = 0, t = 1;
    while (i < 15)
    {
        if (v1[i] == 0)
        {

            temp += t;
        }
        // cout << v1[i] << ' ' << temp << endl;
        if ((temp + 1 + n) % 32768 == 0)
            ans = min(ans, temp + 1);
        else
        {
            ll temp_ans = temp + 1;
            m = temp + 1 + n;
            while (m % 32768)
            {
                m = m << 1;
                temp_ans++;
            }
            ans = min(ans, temp_ans);
        }
        i++;
        t *= 2;
    }
    cout << ans << ' ';
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
