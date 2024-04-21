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
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
void solve()
{
    ll n, i, q, num;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    cin >> q;
    while (q--)
    {
        cin >> num;
        ll l = 0, r = n - 1, mid, res = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v1[mid] < num)
            {
                res = v1[mid];
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (res == -1)
            cout << "X ";
        else
            cout << res << ' ';
        l = 0;
        r = n - 1;
        res = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (v1[mid] > num)
            {
                res = v1[mid];
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (res == -1)
            cout << "X\n";
        else
            cout << res << '\n';
    }
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "CASE# " << t << ":\n";
        solve();
    }
}
