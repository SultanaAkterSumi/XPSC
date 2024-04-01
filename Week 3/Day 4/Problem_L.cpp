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
vector<pair<ll, ll>> v1;
ll n;
ll Binary_Search1(ll a)
{
    ll l = 0, r = n - 1, mid, res = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // cout<<mid<<endl;
        if (v1[mid].first == a)
        {
            res = v1[mid].second;
            r = mid - 1;
        }
        else if (v1[mid].first > a)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}
ll Binary_Search2(ll b)
{
    ll l = 0, r = n - 1, mid, res = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (v1[mid].first == b)
        {
            res = v1[mid].second;
            l = mid + 1;
        }
        else if (v1[mid].first > b)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return res;
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}
void solve()
{
    v1.clear();
    ll q, i, a, b;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        pair<ll, ll> p1;
        cin >> p1.first;
        p1.second = i;
        v1.push_back(p1);
    }
    sort(v1.begin(), v1.end(), cmp);
    while (q--)
    {
        cin >> a >> b;
        ll ans1 = Binary_Search1(a);
        ll ans2 = Binary_Search2(b);
        if (ans1 == -1 || ans2 == -1 || ans1 > ans2)
            no else yes
    }
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