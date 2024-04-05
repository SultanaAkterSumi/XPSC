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

void solve()
{
    ll n, Max = 0, Min = 1023, num, i;
    cin >> n;
    vl v0(12), v1(12);
    for (i = 0; i < n; i++)
    {
        cin >> num;
        Max = max(Max, num);
        Min = min(Min, num);
        ll j = 0;
        while (num)
        {
            if (num % 2)
                v1[j]++;
            else
                v0[j]++;
            j++;
            num /= 2;
        }
    }
    ll a = 0;
    ll temp = 1;
    ll j = 0;
    while (Max)
    {
        if (Max % 2 || v1[j])
        {
            a += temp;
        }
        Max /= 2;
        temp *= 2;
        j++;
    }
    ll b = 0;
    temp = 1;
    j = 0;
    while (Min)
    {
        if (Min % 2)
        {
            if (v0[j] == 0)
                b += temp;
        }
        Min /= 2;
        temp *= 2;
        j++;
    }
    cout << a - b << endl;
}
int main()
{
    op()

        int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}