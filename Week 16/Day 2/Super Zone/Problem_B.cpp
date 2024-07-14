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
    string s1;
    cin >> s1;
    stack<char> st;
    ll c = 0;
    for (auto it : s1)
    {
        if (st.empty())
            st.push(it);
        else
        {
            if (st.top() == it)
            {
                st.pop();
                c++;
            }
            else
                st.push(it);
        }
    }
    if (c % 2)
        yes else no
}
int main()
{
    op() int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}