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
const ll N = 5e5 + 1;
ll ans = 0, n;
vl v1;
void Conquer(ll l, ll mid, ll r)
{
    ll Max = INT64_MIN, Min = INT64_MAX, i, j;
    for (i = l; i <= mid; i++)
        Max = max(Max, v1[i]);
    for (i = mid + 1; i <= r; i++)
        Min = min(Min, v1[i]);
    if (Max > Min)
    {
        ans++;
        vl temp;
        for (i = l; i <= mid; i++)
            temp.push_back(v1[i]);
        for (i = l, j = mid + 1; i <= mid; i++, j++)
            v1[i] = v1[j];
        for (i = mid + 1, j = 0; i <= r; i++, j++)
            v1[i] = temp[j];
    }
}
void Divide(ll l, ll r)
{
    if (l < r)
    {
        ll mid = (r + l - 1) / 2;
        Divide(l, mid);
        Divide(mid + 1, r);
        Conquer(l, mid, r);
    }
}
void solve()
{
    ans = 0;
    v1.clear();
    ll i, num;
    cin >> n;
    v1.push_back(0);
    for (i = 1; i <= n; i++)
    {
        cin >> num;
        v1.push_back(num);
    }
    Divide(1, n);
    bool f = true;
    for (i = 2; i <= n && f; i++)
    {
        if (v1[i - 1] > v1[i])
            f = false;
    }
    if (f)
        cout << ans << endl;
    else
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