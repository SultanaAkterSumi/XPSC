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
const ll N = 1e6 + 1;
ll sum;
map<ll, ll> m1;
bool ans;
void fun(ll x)
{
    if (!ans)
        return;
    if (m1.find(x) != m1.end())
    {
        m1[x]--;
        if (m1[x] == 0)
            m1.erase(x);
    }
    else if (x == 1)
    {
        ans = false;
        return;
    }
    else
    {
        ll x1 = x / 2, x2 = x / 2;
        if (x % 2)
            x1++;
        fun(x1);
        fun(x2);
    }
}
void solve()
{
    ll n, num;
    sum = 0;
    ans = true;
    cin >> n;
    m1.clear();
    while (n--)
    {
        cin >> num;
        sum += num;
        m1[num]++;
    }
    fun(sum);
    if (m1.empty() && ans)
        yes else no
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