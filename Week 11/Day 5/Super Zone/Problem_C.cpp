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
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
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
ll ans = 0;
ll Max_Length(ll n)
{
    v2[n] = true;
    ll temp = 0;
    for (auto it : v1[n])
    {
        if (!v2[it])
            temp += Max_Length(it);
    }
    return temp + 1;
}
void solve()
{
    ll n, i, a, b, sum1 = 0, sum2 = 0, other = 0;
    cin >> n;
    vector<ll> temp(n), v1, v2;
    for (i = 0; i < n; i++)
        cin >> temp[i];
    for (i = 0; i < n; i++)
    {
        a = temp[i];
        cin >> b;
        if (a == b)
            other++;
        else if (a < b)
        {
            v1.push_back(b - a);
            sum1 += (b - a);
        }
        else
        {
            v2.push_back(a - b);
            sum2 += (a - b);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll ans = 0, x = v1.size(), y = v2.size();
    i = x - 1;
    ll j = y - 1;
    while (i >= 0 && j >= 0)
    {
        if (v1[i] < v2[j])
        {
            j--;
            continue;
        }
        ans++;
        i--;
        j--;
    }
    other += (i + 1);
    ans += (other / 2);
    cout << ans << endl;
}
int main()
{
    op() int tc = 1;
    // Sieve();
    cin >> tc;
    // cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case "<<t<<": ";
        // cout<<"Scenario #"<<t<<": ";
        solve();
    }
}