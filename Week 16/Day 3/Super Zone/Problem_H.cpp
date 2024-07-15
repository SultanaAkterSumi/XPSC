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
const ll N = 2e5 + 1;

void solve()
{
    ll n, i, tt = 0;
    cin >> n;
    vl v1(n), v2(n), v3(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    for (i = 0; i < n; i++)
        cin >> v2[i];
    for (i = 0; i < n; i++)
    {
        cin >> v3[i];
        tt += v3[i];
    }
    ll sum = 0, req = tt / 3;
    if (tt % 3)
        req++;
    for (i = 0; i < n; i++)
    {
        sum += v1[i];
        if (req <= sum)
            break;
    }
    vector<pair<ll, ll>> a, b, c;
    a.push_back({0, i});

    sum = 0;
    for (i = n - 1; i >= 0; i--)
    {
        sum += v1[i];
        if (req <= sum)
            break;
    }
    a.push_back({i, n - 1});

    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += v2[i];
        if (req <= sum)
            break;
    }
    b.push_back({0, i});

    sum = 0;
    for (i = n - 1; i >= 0; i--)
    {
        sum += v2[i];
        if (req <= sum)
            break;
    }
    b.push_back({i, n - 1});

    sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += v3[i];
        if (req <= sum)
            break;
    }
    c.push_back({0, i});

    sum = 0;
    for (i = n - 1; i >= 0; i--)
    {
        sum += v3[i];
        if (req <= sum)
            break;
    }
    c.push_back({i, n - 1});
    // cout << a[0].first << ' ' << a[0].second << endl;
    // cout << a[1].first << ' ' << a[1].second << endl;
    // cout << b[0].first << ' ' << b[0].second << endl;
    // cout << b[1].first << ' ' << b[1].second << endl;
    // cout << c[0].first << ' ' << c[0].second << endl;
    // cout << c[1].first << ' ' << c[1].second << endl;
    if (b[1].first - a[0].second > 1)
    {

        sum = 0;
        for (i = a[0].second + 1; i < b[1].first; i++)
            sum += v3[i];
        if (sum >= req)
        {

            cout << a[0].first + 1 << ' ' << a[0].second + 1 << ' ' << b[1].first + 1 << ' ' << b[1].second + 1 << ' ' << a[0].second + 2 << ' ' << b[1].first << endl;
            return;
        }
    }

    if (c[1].first - a[0].second > 1)
    {

        sum = 0;
        for (i = a[0].second + 1; i < c[1].first; i++)
            sum += v2[i];
        if (sum >= req)
        {

            cout << a[0].first + 1 << ' ' << a[0].second + 1 << ' ' << a[0].second + 2 << ' ' << c[1].first << ' ' << c[1].first + 1 << ' ' << c[1].second + 1 << endl;
            return;
        }
    }

    if (a[1].first - b[0].second > 1)
    {
        sum = 0;
        for (i = b[0].second + 1; i < a[1].first; i++)
            sum += v3[i];
        if (sum >= req)
        {
            cout << a[1].first + 1 << ' ' << a[1].second + 1 << ' ' << b[0].first + 1 << ' ' << b[0].second + 1 << ' ' << b[0].second + 2 << ' ' << a[1].first << endl;
            return;
        }
    }

    if (c[1].first - b[0].second > 1)
    {
        sum = 0;
        for (i = b[0].second + 1; i < c[1].first; i++)
            sum += v1[i];
        if (sum >= req)
        {
            cout << b[0].second + 2 << ' ' << c[1].first << ' ' << b[0].first + 1 << ' ' << b[0].second + 1 << ' ' << c[1].first + 1 << ' ' << c[1].second + 1 << endl;
            return;
        }
    }

    if (a[1].first - c[0].second > 1)
    {
        sum = 0;
        for (i = c[0].second + 1; i < a[1].first; i++)
            sum += v2[i];
        if (sum >= req)
        {
            cout << a[1].first + 1 << ' ' << a[1].second + 1 << ' ' << c[0].second + 2 << ' ' << a[1].first << ' ' << c[0].first + 1 << ' ' << c[0].second + 1 << endl;
            return;
        }
    }

    if (b[1].first - c[0].second > 1)
    {
        sum = 0;
        for (i = c[0].second + 1; i < b[1].first; i++)
            sum += v1[i];
        if (sum >= req)
        {
            cout << c[0].second + 2 << ' ' << b[1].first << ' ' << b[1].first + 1 << ' ' << b[1].second + 1 << ' ' << c[0].first + 1 << ' ' << c[0].second + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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