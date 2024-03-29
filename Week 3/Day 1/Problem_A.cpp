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

void solve()
{
    ll n, m = 0, e = 0, o = 0, w = 0, other = 0;
    string s1;
    cin >> n >> s1;

    for (auto it : s1)
    {

        if (it == 'm' || it == 'M')
        {
            if (e || o || w)
            {
                no return;
            }
            m++;
        }
        else if (it == 'e' || it == 'E')
        {
            if (m == 0 || o || w)
            {
                no return;
            }
            e++;
        }
        else if (it == 'o' || it == 'O')
        {
            if (m == 0 || e == 0 || w)
            {
                no return;
            }
            o++;
        }
        else if (it == 'w' || it == 'W')
        {
            if (m == 0 || e == 0 || o == 0)
            {
                no return;
            }
            w++;
        }
        else
        {
            no return;
        }
    }
    if (m == 0 || e == 0 || o == 0 || w == 0)
    {
        no return;
    }
    yes
}
int main()
{
    op() int tc = 1;
    cin >> tc;
    //  cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ":\n";
        //  cout<<"Scenario #"<<t<<": ";
        solve();
    }
}