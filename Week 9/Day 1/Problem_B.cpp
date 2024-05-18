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
const ll MOD = 1e9 + 7;
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}
void solve()
{
    ll n, x, num, i, j;
    cin >> n >> x;
    vector<pair<ll, ll>> v1;
    for (i = 1; i <= n; i++)
    {
        cin >> num;
        v1.push_back({num, i});
    }
    sort(v1.begin(), v1.end(), cmp);
    ll temp;
    ll ans1 = -1, ans2 = -1, ans3 = -1;
    for (i = 0; i < n - 2; i++)
    {
        if (x <= v1[i].first)
            break;
        for (j = i + 1; j < n - 1; j++)
        {
            temp = x - v1[i].first - v1[j].first;
            if (temp <= 0)
                break;
            ll l = j + 1, r = n - 1, mid;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (v1[mid].first == temp)
                {
                    ans1 = i;
                    ans2 = j, ans3 = mid;
                    break;
                }
                else if (v1[mid].first > temp)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if (ans1 != -1)
                break;
        }
        if (ans1 != -1)
            break;
    }

    if (ans1 != -1)
        cout << v1[ans1].second << ' ' << v1[ans2].second << ' ' << v1[ans3].second << endl;
    else
        cout << "IMPOSSIBLE\n";
}

int main()
{
    op() int tc = 1;
    // cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}