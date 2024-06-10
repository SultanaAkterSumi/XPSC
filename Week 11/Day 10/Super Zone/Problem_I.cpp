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
// Sieve
bool isprime[1000009];
void Sieve()
{
    memset(isprime, true, sizeof(isprime));
    ll i, j, limit = sqrt(1000009 * 1.) + 2;
    isprime[1] = false;
    for (i = 4; i < 1000009; i += 2)
        isprime[i] = false;
    for (i = 3; i < 1000009; i += 2)
    {
        if (isprime[i])
        {
            if (i < limit)
            {
                for (j = i * i; j < 1000009; j += i * 2)
                    isprime[j] = false;
            }
        }
    }
}

// vl v1;
// ll n;
// ll Binary_Search(ll total)
// {
//     ll l = 1, r = n, mid, res = -1;
//     while (l <= r)
//     {
//         mid = (l + r) / 2;
//         if (v1[mid] <= total)
//             l = mid + 1;
//         else
//         {
//             res = mid;
//             r = mid - 1;
//         }
//     }
//     return res;
// }
vector<vector<ll>> v1(100001);
vector<bool> v2(100001, false);
void Visited(ll n)
{
    for (auto it : v1[n])
    {
        if (!v2[it])
        {
            v2[it] = true;
        }
    }
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}
void solve()
{
    ll n, k, i, turn = 1, num = 1, j;
    cin >> n >> k;
    vector<ll> v1, ans(n + 1);
    for (i = 1; i <= k; i++)
    {
        ll t1 = i, sz = 0;
        v1.clear();
        while (t1 <= n)
        {
            v1.push_back(t1);
            t1 += k;
            sz++;
        }
        if (turn == 1)
        {
            for (j = 0; j < sz; j++)
            {
                ans[v1[j]] = num;
                num++;
            }
            turn = 0;
        }
        else
        {
            for (j = sz - 1; j >= 0; j--)
            {
                ans[v1[j]] = num;
                num++;
            }
            turn = 1;
        }
    }
    for (i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}
int main()
{
    op() int tc = 1;
    // Sieve();
    cin >> tc;
    // cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ":\n";
        //  cout<<"Scenario #"<<t<<": ";
        solve();
    }
}