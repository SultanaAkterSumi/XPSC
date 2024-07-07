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
const ll N = 1e5 + 1;
const ll MOD = 998244353;

void solve()
{
    ll n, c, q, l, r, i, x;
    string s1;
    cin >> n >> c >> q >> s1;
    vl v1;
    vector<pair<ll, ll>> v2;
    v1.push_back(n);
    v2.push_back({1, n});
    while (c--)
    {
        cin >> l >> r;
        v1.push_back(r - l + 1);
        v2.push_back({l, r});
    }
    ll m = v1.size();
    for (i = 1; i < m; i++)
        v1[i] += v1[i - 1];
    while (q--)
    {
        cin >> x;

        for (i = 0; i < m; i++)
        {
            if (v1[i] >= x)
                break;
        }
        while (1)
        {
            x = v2[i].second - (v1[i] - x);
            if (x <= n)
                break;
            for (; i >= 0; i--)
            {
                if (v1[i] < x)
                {
                    i++;
                    break;
                }
            }
        }
        cout << s1[x - 1] << endl;
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