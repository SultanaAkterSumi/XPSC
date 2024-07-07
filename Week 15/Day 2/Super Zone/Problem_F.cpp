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
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}
bool cmp1(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.second < b.second;
}
void solve()
{
    ll n, i, j, num;
    cin >> n;
    vector<pair<ll, ll>> v1;
    vl v2(n + 1, 2), v3;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        v1.push_back({num, i});
        v2[num]--;
    }
    sort(v1.begin(), v1.end(), cmp);
    for (i = 1; i <= n; i++)
    {
        if (v2[i] == 2)
            v3.push_back(i);
    }
    sort(v3.begin(), v3.end());

    vector<pair<ll, ll>> ans1, ans2;
    for (i = n - 1; i >= 0; i--)
    {
        ll sz = 1;
        while (i - 1 >= 0 && v1[i].first == v1[i - 1].first)
        {
            i--;
            sz++;
        }
        if (sz > 2)
        {
            no return;
        }
        if (sz == 1)
        {
            ans1.push_back({v1[i].first, v1[i].second});
            ans2.push_back({v1[i].first, v1[i].second});
        }
        else
        {

            ans1.push_back({v1[i].first, v1[i].second});
            ans2.push_back({v1[i].first, v1[i + 1].second});
            while (!v3.empty() && v3.back() > v1[i].first)
                v3.pop_back();
            if (v3.empty())
            {
                no return;
            }
            ans1.push_back({v3.back(), v1[i + 1].second});
            ans2.push_back({v3.back(), v1[i].second});
            v3.pop_back();
        }
        // cout << "ans:\n";
        // for (auto it : ans1)
        //     cout << it.first << ' ' << it.second << endl;
        // for (auto it : ans2)
        //     cout << it.first << ' ' << it.second << endl;
    }
    sort(ans1.begin(), ans1.end(), cmp1);
    sort(ans2.begin(), ans2.end(), cmp1);
    yes for (i = 0; i < n; i++) cout << ans1[i].first << ' ';
    cout << endl;
    for (i = 0; i < n; i++)
        cout << ans2[i].first << ' ';
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