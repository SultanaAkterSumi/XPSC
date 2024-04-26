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
const ll MOD = 998244353;

ll Binary_Search(const vl &v1, ll n, ll x)
{
    ll low = 1, high = INT_MAX, mid, h = 1, c;
    while (low <= high)
    {
        mid = (low + high) / 2;
        c = 0;
        for (ll i = 0; i < n; i++)
        {
            if (v1[i] < mid)
                c += (mid - v1[i]);
            else
                break;
        }
        if (c < x)
        {
            h = mid;
            low = mid + 1;
        }
        else if (c == x)
            return mid;
        else
        {
            high = mid - 1;
        }
    }
    return h;
}
void solve()
{
    ll n, x, i, num;
    cin >> n >> x;
    vl v1;
    for (i = 0; i < n; i++)
    {
        cin >> num;
        v1.push_back(num);
    }
    sort(v1.begin(), v1.end());
    cout << Binary_Search(v1, n, x) << endl;
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
