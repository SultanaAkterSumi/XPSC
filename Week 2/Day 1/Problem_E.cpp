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
vl v1;
ll n;
ll Binary_Search(ll total)
{
    ll l = 1, r = n, mid, res = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (v1[mid] <= total)
            l = mid + 1;
        else
        {
            res = mid;
            r = mid - 1;
        }
    }
    return res;
}
void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    if (a + b == c)
        cout << "+\n";
    else
        cout << "-\n";
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