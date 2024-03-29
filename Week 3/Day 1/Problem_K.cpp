#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define gcd(a, b) __gcd(a, b)
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 2e5 + 9;
const ll MOD = 1e9 + 7;

bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first > b.first;
}

void solve()
{
    ll n, i, num, ans;
    cin >> n;
    vector<pair<ll, ll>> a(n), b(n), c(n);
    for (i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    for (i = 0; i < n; i++)
    {
        cin >> b[i].first;
        b[i].second = i;
    }
    for (i = 0; i < n; i++)
    {
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    sort(c.begin(), c.end(), cmp);

    // a->b->c
    ans = 0;
    ll x;
    ll t1 = a[0].first;
    if (a[0].second != b[0].second)
    {
        t1 += b[0].first;
        x = b[0].second;
    }
    else
    {
        t1 += b[1].first;
        x = b[1].second;
    }
    if (a[0].second != c[0].second && x != c[0].second)
        t1 += c[0].first;
    else if (a[0].second != c[1].second && x != c[1].second)
        t1 += c[1].first;
    else
        t1 += c[2].first;
    ans = max(ans, t1);

    // a->c->b
    t1 = a[0].first;
    if (a[0].second != c[0].second)
    {
        t1 += c[0].first;
        x = c[0].second;
    }
    else
    {
        t1 += c[1].first;
        x = c[1].second;
    }
    if (a[0].second != b[0].second && x != b[0].second)
        t1 += b[0].first;
    else if (a[0].second != b[1].second && x != b[1].second)
        t1 += b[1].first;
    else
        t1 += b[2].first;
    ans = max(ans, t1);

    // b->a->c
    t1 = b[0].first;
    if (b[0].second != a[0].second)
    {
        t1 += a[0].first;
        x = a[0].second;
    }
    else
    {
        t1 += a[1].first;
        x = a[1].second;
    }
    if (b[0].second != c[0].second && x != c[0].second)
        t1 += c[0].first;
    else if (b[0].second != c[1].second && x != c[1].second)
        t1 += c[1].first;
    else
        t1 += c[2].first;
    ans = max(ans, t1);

    // b->c->a
    t1 = b[0].first;
    if (b[0].second != c[0].second)
    {
        t1 += c[0].first;
        x = c[0].second;
    }
    else
    {
        t1 += c[1].first;
        x = c[1].second;
    }
    if (b[0].second != a[0].second && x != a[0].second)
        t1 += a[0].first;
    else if (b[0].second != a[1].second && x != a[1].second)
        t1 += a[1].first;
    else
        t1 += a[2].first;
    ans = max(ans, t1);

    // c->a->b
    t1 = c[0].first;
    if (c[0].second != a[0].second)
    {
        t1 += a[0].first;
        x = a[0].second;
    }
    else
    {
        t1 += a[1].first;
        x = a[1].second;
    }
    if (c[0].second != b[0].second && x != b[0].second)
        t1 += b[0].first;
    else if (c[0].second != b[1].second && x != b[1].second)
        t1 += b[1].first;
    else
        t1 += b[2].first;
    ans = max(ans, t1);

    // c->b->a
    t1 = c[0].first;
    if (c[0].second != b[0].second)
    {
        t1 += b[0].first;
        x = b[0].second;
    }
    else
    {
        t1 += b[1].first;
        x = b[1].second;
    }
    if (c[0].second != a[0].second && x != a[0].second)
        t1 += a[0].first;
    else if (c[0].second != a[1].second && x != a[1].second)
        t1 += a[1].first;
    else
        t1 += a[2].first;
    ans = max(ans, t1);
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