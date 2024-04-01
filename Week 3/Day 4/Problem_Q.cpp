#include <bits/stdc++.h>
using namespace std;

#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

typedef long long ll;

void solve()
{
    ll n, i;
    cin >> n;
    vector<ll> v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    ll ans = INT_MIN;
    for (i = 1; i < n; i++)
        ans = max(ans, v1[i] - v1[0]);
    for (i = 0; i < n - 1; i++)
        ans = max(ans, v1[n - 1] - v1[i]);
    for (i = 1; i < n; i++)
        ans = max(ans, v1[i - 1] - v1[i]);
    if (n == 1)
        ans = 0;
    cout << ans << endl;
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