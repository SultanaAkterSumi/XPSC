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
const ll N = 2e5 + 1;
const ll MOD = 1e9 + 7;

void solve()
{
    ll n, q, i, num, l, r, mid, res, t = 1;
    vl v1;
    while (1)
    {
        cin >> n >> q;
        if (n == 0 && q == 0)
            break;
        for (i = 0; i < n; i++)
        {
            cin >> num;
            v1.push_back(num);
        }
        sort(v1.begin(), v1.end());
        // for (auto it : v1)
        //     cout << it << ' ';
        // cout << endl;
        cout << "CASE# " << t << ":\n";
        while (q--)
        {

            cin >> num;
            cout << num << ' ';
            l = 0;
            r = n - 1;
            res = 0;
            while (l <= r)
            {
                mid = (l + r) / 2;
                if (v1[mid] == num)
                {
                    res = mid + 1;
                    r = mid - 1;
                }
                else if (v1[mid] > num)
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            if (res)
                cout << "found at " << res << endl;
            else
                cout << "not found\n";
        }
        v1.clear();
        t++;
    }
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "CASE# " << t << ":\n";
        solve();
    }
}
