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
const ll N = 1e5 + 9;
const ll MOD = 1e9 + 7;
vl dec_palindrom;
bool is_palindrom(ll num)
{
    string s1 = to_string(num);
    ll i, n = s1.size();
    ll m = n / 2;
    for (i = 0; i < m; i++)
    {
        if (s1[i] != s1[n - i - 1])
            return false;
    }
    return true;
}
void solve()
{
    ll n, i, num;
    cin >> n;
    vl v1(33000);
    set<ll> s1;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        v1[num]++;
        s1.insert(num);
    }

    ll ans1 = 0, ans2 = 0;
    ll m = dec_palindrom.size();
    for (auto it : s1)
    {
        // cout << it << endl;
        for (i = 0; i < m; i++)
        {
            ll t1 = (it ^ dec_palindrom[i]);

            if (t1 >= 32768)
                continue;
            ans1 += (v1[t1] * v1[it]);
        }
        ans2 += ((v1[it] * (v1[it] + 1)) / 2);
    }
    cout << (ans1 / 2) + ans2 << endl;
}
int main()
{
    op()
        ll i;
    for (i = 1; i < 32768; i++)
    {
        if (is_palindrom(i))
        {
            dec_palindrom.push_back(i);
        }
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}