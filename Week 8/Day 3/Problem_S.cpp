#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define yes cout << "Yes\n";
#define no cout << "No\n";
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0)
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef vector<ll> vl;
const ll N = 1e5 + 1;
const ll MOD = 998244353;
bool isPrime(ll n)
{
    if (n == 1)
        return false;
    ll i, m = sqrt(n);
    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve()
{
    ll n, i, q, num;
    cin >> n;
    vl v1(n), v2(n);
    for (i = 0; i < n; i++)
    {
        cin >> num;
        if (num == 1)
            v1[i] = 1;
        else if (num == 2)
            v2[i] = 1;
        if (i)
        {
            v1[i] += v1[i - 1];
            v2[i] += v2[i - 1];
        }
    }
    cin >> q;
    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        ll c1 = v1[r];

        if (l)
            c1 -= v1[l - 1];
        ll c2 = v2[r];
        if (l)
            c2 -= v2[l - 1];

        ll other = (r - l + 1) - (c1 + c2);
        // cout << other << endl;
        if (other >= k)
        {
            ll temp = min(abs(c1 - c2), k);
            k -= temp;
            if (c1 < c2)
                c1 += temp;
            else
                c2 += temp;
            if (k)
            {
                temp = k / 2;
                c1 += temp;
                c2 += (k - temp);
            }
        }
        else
        {
            k -= other;
            ll temp = min(abs(c1 - c2), other);
            other -= temp;
            if (c1 < c2)
                c1 += temp;
            else
                c2 += temp;
            if (other)
            {
                temp = other / 2;
                c1 += temp;
                c2 += (other - temp);
            }
            temp = abs(c1 - c2);
            if (temp % 2)
                temp--;
            temp /= 2;
            temp = min(temp, k);
            if (c1 > c2)
            {
                c1 -= temp;
                c2 += temp;
            }
            else
            {
                c2 -= temp;
                c1 += temp;
            }
        }
        cout << c1 * c2 << endl;
    }
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