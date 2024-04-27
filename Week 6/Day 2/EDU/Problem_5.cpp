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
    string s1;
    ll nb, ns, nc, pb, ps, pc, r, sb = 0, ss = 0, sc = 0;
    cin >> s1 >> nb >> ns >> nc >> pb >> ps >> pc >> r;
    // cout << s1 << endl;
    for (auto it : s1)
    {
        if (it == 'B')
            sb++;
        else if (it == 'S')
            ss++;
        else
            sc++;
    }
    // cout << sb << ' ' << ss << ' ' << sc << endl;
    ll cb = 0, cs = 0, cc = 0;
    if (sb)
        cb = nb / sb;
    if (ss)
        cs = ns / ss;
    if (sc)
        cc = nc / sc;

    ll Min = min({cb, cs, cc}), Max = max({cb, cs, cc});
    ll rem_b = nb - (Min * sb), rem_s = ns - (Min * ss), rem_c = nc - (Min * sc);
    // cout << rem_b << ' ' << rem_s << ' ' << rem_c << endl;
    ll cost;
    while (((rem_b && sb) || (rem_c && sc) || (rem_s && ss)) && r)
    {
        cost = 0;
        if (rem_b > sb)
        {
            rem_b -= sb;
        }
        else
        {
            cost += (sb - rem_b) * pb;
            rem_b = 0;
        }
        if (rem_s > ss)
        {
            rem_s -= ss;
        }
        else
        {
            cost += (ss - rem_s) * ps;
            rem_s = 0;
        }
        if (rem_c > sc)
        {
            rem_c -= sc;
        }
        else
        {
            cost += (sc - rem_c) * pc;
            rem_c = 0;
        }
        if (cost <= r)
        {
            r -= cost;
            Min++;
        }
        else
            break;
        // cout << Min << endl;
    }
    // cout << Min << endl;
    if (r)
    {
        cost = (sb * pb) + (ss * ps) + (sc * pc);
        Min += (r / cost);
    }
    cout << Min << endl;
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}