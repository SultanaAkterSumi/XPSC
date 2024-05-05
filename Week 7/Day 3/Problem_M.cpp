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
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, q, i, num, j;
    cin >> n >> q;
    vl v1(n), v2;
    for (i = 0; i < n; i++)
        cin >> v1[i];
    ll curr = 31;
    while (q--)
    {
        cin >> num;
        if (num < curr)
        {
            v2.push_back(num);
            curr = num;
        }
    }
    q = v2.size();
    for (i = 0; i < n; i++)
    {
        if (v1[i] & 1)
        {
            cout << v1[i] << ' ';
            continue;
        }

        ll temp = v1[i], c = 0;

        while ((temp & 1) == 0)
        {

            c++;
            temp = temp >> 1;
            // cout << c << endl;
        }

        for (j = 0; j < q; j++)
        {
            if (v2[j] <= c)
            {

                v1[i] += (1 << (v2[j] - 1));
                c = v2[j] - 1;
            }
        }
        cout << v1[i] << ' ';
    }
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