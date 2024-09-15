#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set1 = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set2 = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 9;
ll n, m1, m2, a, b, ans = INT64_MAX;
vector<vector<bool>> v1(N, vector<bool>(N, false)), v2(N, vector<bool>(N, false));
vector<vl> c(N, vl(N));
vl v3;
vector<pair<pair<ll, ll>, ll>> v4;
void Fun(ll l, ll r, vector<vector<bool>> temp, ll cost)
{

    vl temp1;
    ll i, j;
    for (i = 1; i <= n; i++)
    {
        ll cnt = 0;
        for (j = 1; j <= n; j++)
        {
            if (temp[i][j])
                cnt++;
        }
        temp1.push_back(cnt);
    }
    sort(temp1.begin(), temp1.end());
    if (v3 == temp1)
    {
        ans = min(ans, cost);
        return;
    }
    if (l >= n)
        return;
    if (r + 1 > n)
        Fun(l + 1, l + 2, temp, cost);
    else
        Fun(l, r + 1, temp, cost);
    if (temp[l][r])
        temp[l][r] = false, temp[r][l] = false;
    else
        temp[l][r] = true, temp[r][l] = true;
    if (r + 1 > n)
        Fun(l + 1, l + 2, temp, cost + c[l][r]);
    else
        Fun(l, r + 1, temp, cost + c[l][r]);
}
void solve()
{
    ll n, a, e, i, o, u;
    cin >> n;
    a = n / 5, e = n / 5,
    i = n / 5, o = n / 5,
    u = n / 5;
    n %= 5;
    if (n > 0)
        a++;
    n--;
    if (n > 0)
        e++;
    n--;
    if (n > 0)
        i++;
    n--;
    if (n > 0)
        o++;
    while (a--)
        cout << 'a';
    while (e--)
        cout << 'e';
    while (i--)
        cout << 'i';
    while (o--)
        cout << 'o';
    while (u--)
        cout << 'u';
    cout << endl;
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