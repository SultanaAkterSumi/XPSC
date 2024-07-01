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
    ll n, m, i;
    cin >> n >> m;
    vl v1(m);
    for (i = 0; i < m; i++)
        cin >> v1[i];
    sort(v1.begin(), v1.end());
    vl v2;
    for (i = 1; i < m; i++)
    {
        v2.push_back(v1[i] - v1[i - 1] - 1);
    }
    v2.push_back(n - v1[m - 1] + v1[0] - 1);
    sort(v2.rbegin(), v2.rend());
    ll cnt = 0;
    ll save = 0;
    ll k = v2.size();

    for (i = 0; i < k; i++)
    {
        if (v2[i] <= cnt)
            break;
        if (v2[i] - (cnt + 1) <= 0)
            save++;
        else
            save += (v2[i] - (cnt + 1));
        cnt += 4;
    }
    cout << n - save << endl;
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