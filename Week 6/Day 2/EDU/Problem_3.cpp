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

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}
void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    // cout << s1 << endl
    //      << s2 << endl;
    ll i, num, n = s1.size(), m = s2.size();
    vector<pair<ll, ll>> v1;
    for (i = 1; i <= n; i++)
    {
        cin >> num;
        v1.push_back({num, i});
    }
    sort(v1.begin(), v1.end(), cmp);
    // for (auto it : v1)
    //     cout << it.first << ' ' << it.second << endl;
    ll l = 0, r = n, mid, res;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // cout << l << ' ' << r << ' ' << mid << endl;
        ll x = 0;
        for (i = 1; i <= n; i++)
        {
            if (v1[i - 1].second > mid)
            {
                // cout << i << ' ';
                if (s1[i - 1] == s2[x])
                    x++;
                if (x == m)
                    break;
            }
        }
        // cout << x << endl;
        if (x == m)
        {

            res = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << res << endl;
}

int main()
{
    op()

        int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}
