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

void solve()
{
    ll n, m, k, i, num;
    cin >> n >> m >> k;
    vector<vl> v1(m, vl(20, 0));
    for (i = 0; i < m; i++)
    {
        cin >> num;
        // cout << num << endl;
        ll j = 0;
        while (num)
        {
            if (num % 2)
                v1[i][j] = 1;
            j++;
            num /= 2;
        }
    }
    cin >> num;

    vl fedor(20, 0);
    ll temp = num;
    ll j = 0;
    while (temp)
    {
        if (temp % 2)
            fedor[j] = 1;
        j++;
        temp /= 2;
    }
    ll ans = 0;
    for (i = 0; i < m; i++)
    {
        ll temp = num;
        ll c = 0;
        for (j = 0; j < 20 && c <= k; j++)
        {
            if (fedor[j] != v1[i][j])
                c++;
        }
        if (c <= k)
            ans++;
    }
    cout << ans;
}
int main()
{
    op()

        int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}