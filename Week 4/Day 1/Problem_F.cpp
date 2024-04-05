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
    ll n, i, ans = 0;
    cin >> n;
    // cout<<n<<endl;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }

    sort(v1.begin(), v1.end());
    // for (i = 0; i < n; i++){
    // cout<<v1[i]<<' ';} cout<<endl;
    ll temp = 1, temp1 = 2;
    i = 0;
    ll cnt;
    while (i < n)
    {
        cnt = 0;

        while (i < n && v1[i] <= temp)
        {
            // cout<<temp<<' '<<v1[i]<<endl;
            cnt++;
            i++;
        }

        if (cnt > 1)
        {
            ans += ((cnt * (cnt - 1)) / 2);
        }
        temp += temp1;
        temp1 *= 2;
    }
    cout << ans << endl;
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