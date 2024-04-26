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
const ll N = 1e5 + 1;
const ll MOD = 998244353;

void solve()
{
    ll n, q, i, a, b;
    cin >> n >> q;
    vector<ll> v1(n + 1, 0);
    for (i = 1; i <= n; i++)
        cin >> v1[i];
    vector<ll> v2(n + 1, 0);
    for (i = 1; i <= n; i++)
        v2[i] = v1[i] + v2[i - 1];
    vector<ll> ans(q);
    vector<pair<ll, ll>> k(q);
    for (i = 0; i < q; i++)
    {
        cin >> k[i].first;
        k[i].second = i;
    }
    sort(k.begin(), k.end());
    b = 0; // index
    for (i = 0; i < q; i++)
    {
        while (1)
        {
            if (b == n || k[i].first < v1[b + 1])
                break;
            b++;
        }
        ans[k[i].second] = v2[b];
    }
    for (i = 0; i < q; i++)
        cout << ans[i] << ' ';
    cout << '\n';
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
