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
const ll N = 1e5 + 9;
vl a(N), lazy(4 * N);

void propagate(ll m, ll b, ll e)
{

    if (b != e)

    {
        lazy[2 * m] += lazy[m], lazy[2 * m + 1] += lazy[m];
        lazy[m] = 0;
    }
}
void update(ll m, ll b, ll e, ll l, ll r)
{
    propagate(m, b, e);
    if (r < b || l > e)
        return;
    if (b == l && e == r)
    {
        lazy[m]++;
        propagate(m, b, e);
        return;
    }
    ll mid = (b + e) / 2;
    update(2 * m, b, mid, l, min(mid, r));
    update(2 * m + 1, mid + 1, e, max(l, mid + 1), r);
}
ll query(ll m, ll b, ll e, ll l, ll r)
{
    propagate(m, b, e);
    if (r < b || l > e)
        return 0;
    if (l == b && r == e)
        return lazy[m];
    ll mid = (b + e) / 2;
    return query(2 * m, b, mid, l, min(mid, r)) + query(2 * m + 1, mid + 1, e, max(l, mid + 1), r);
}
int main()
{
    op()
        ll test,
        j;
    cin >> test;
    for (j = 1; j <= test; j++)
    {
        cout << "Case " << j << ":\n";
        ll n,
            m, num, l, r, i;
        string s1;
        cin >> s1 >> m;
        n = s1.size();
        for (i = 1; i <= n; i++)
            a[i] = s1[i - 1] - '0';
        ll temp = 4 * N;
        for (i = 1; i < temp; i++)
            lazy[i] = 0;
        while (m--)
        {
            cin >> s1;
            if (s1 == "I")
            {
                cin >> l >> r;
                update(1, 1, n, l, r);
            }
            else
            {
                cin >> l;

                cout << (a[l] ^ (query(1, 1, n, l, l) % 2)) << endl;
            }
        }
    }
}