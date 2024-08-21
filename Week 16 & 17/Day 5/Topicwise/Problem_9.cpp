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
const ll MAX = 1e9 + 7;
const ll N = 2e5 + 9;
vl a(N), t(4 * N);
void build(ll m, ll l, ll r)
{
    if (l == r)
    {
        t[m] = a[l];
        return;
    }
    ll mid = (l + r) / 2;
    build(2 * m, l, mid);
    build(2 * m + 1, mid + 1, r);

    t[m] = gcd(t[2 * m], t[2 * m + 1]);
}

ll GCD(ll m, ll l, ll r, ll i, ll j)
{
    if (j < l || i > r)
        return 0;
    if (l == i && r == j)
        return t[m];
    ll mid = (l + r) / 2;
    ll ans1 = GCD(2 * m, l, mid, i, min(mid, j));
    ll ans2 = GCD(2 * m + 1, mid + 1, r, max(mid + 1, i), j);
    if (ans1 && ans2)
        return gcd(ans1, ans2);
    else if (ans1)
        return ans1;
    else
        return ans2;
}

int main()
{
    op()
        ll n,
        i;
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);
    ll l = 1, r = n, mid, res = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        bool f = false;
        ll s = 1, e = s + mid - 1;
        while (e <= n && !f)
        {
            ll ans = GCD(1, 1, n, s, e);
            s++;
            e++;
            if (ans == 1)
                f = true;
        }
        if (f)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << res << endl;
}