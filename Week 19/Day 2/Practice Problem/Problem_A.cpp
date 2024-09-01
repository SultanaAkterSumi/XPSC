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

int main()
{
    op() string st;
    cin >> st;
    ll i, j = 0, n = st.size();
    ll v = 0;
    vl v1;
    set<ll> s1;
    for (i = 0; i < n; i++)
    {

        if (st[i] == 'o')
        {

            if (v > 1)
            {
                v1.push_back(v - 1);
                j++;
            }
            v1.push_back(0);
            s1.insert(j);
            j++;
            v = 0;
        }
        else
        {
            v++;
        }
    }
    if (v > 1)
    {
        v1.push_back(v - 1);
        v = 0;
        j++;
    }
    n = j;

    for (i = 1; i < n; i++)
        v1[i] += v1[i - 1];
    ll ans = 0;
    for (auto it : s1)
    {
        ans += (v1[it] * (v1[n - 1] - v1[it]));
    }
    cout << ans;
}