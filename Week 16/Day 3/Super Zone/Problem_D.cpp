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
typedef long double ld;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const ll MOD = 1e9 + 7;
const ll N = 1e5 + 1;

void solve()
{
    ll n, i, j;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    i = 0;
    j = n - 1;
    set<ll> s1;
    bool f1 = true;
    while (i < j && f1)
    {
        if (v1[i] != v1[j])
        {
            if (s1.count(v1[i]))
                i++;
            else if (s1.count(v1[j]))
                j--;
            else
            {
                if (s1.size() == 1)
                    f1 = false;
                else
                {
                    s1.insert(v1[i]);
                    i++;
                }
            }
        }
        else
        {
            i++;
            j--;
        }
    }

    i = 0;
    j = n - 1;
    s1.clear();
    bool f2 = true;
    while (i < j && f2)
    {
        if (v1[i] != v1[j])
        {
            if (s1.count(v1[i]))
                i++;
            else if (s1.count(v1[j]))
                j--;
            else
            {
                if (s1.size() == 1)
                    f2 = false;
                else
                {
                    s1.insert(v1[j]);
                    j--;
                }
            }
        }
        else
        {
            i++;
            j--;
        }
    }
    if (f1 || f2)
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