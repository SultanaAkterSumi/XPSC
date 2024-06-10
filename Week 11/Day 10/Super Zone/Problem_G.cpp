#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set1 = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set2 = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
typedef pair<ll, ll> pll;
const ll N = 2e5 + 1;
const ll MOD = 1e9 + 7;
vector<vl> sparse(N, vl(20));
ll n;
vl v1(N);
void build()
{
    ll i, j;
    ll m = log2(n) + 1;
    for (i = 0; i < n; i++)
        sparse[i][0] = v1[i];
    for (j = 1; (1 << j) <= n; j++)
    {
        for (i = 0; i + (1 << j) - 1 < n; i++)
        {
            if (sparse[i][j - 1] > sparse[i + (1 << (j - 1))][j - 1])
                sparse[i][j] = sparse[i][j - 1];
            else
                sparse[i][j] = sparse[i + (1 << (j - 1))][j - 1];
        }
    }
}
ll query(ll l, ll r)
{
    ll m = log2(r - l + 1);
    return max(sparse[l][m], sparse[r - (1 << m) + 1][m]);
}
void solve()
{
    string s1;
    cin >> s1;
    n = s1.size() + 1;
    ll i, c = 0;
    for (i = 1; i < n; i++)
    {
        if (s1[i - 1] == '(')
            c++;
        else
            c--;
        v1[i] = c;
    }
    build();
    c = 0;
    map<ll, deque<ll>> m1;
    for (i = 0; i < n; i++)
    {
        deque<ll> &d = m1[v1[i]];
        while (!d.empty())
        {
            if (v1[i] - (query(d.front(), i) - v1[i]) < 0)
                d.pop_front();
            else
                break;
        }
        c += d.size();
        d.push_back(i);
    }
    cout << c << endl;
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