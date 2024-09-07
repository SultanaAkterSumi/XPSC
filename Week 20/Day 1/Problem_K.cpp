#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set1 = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_set2 = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
const ll N = 2e5 + 1;

void solve()
{
    ll n, i, j;
    string s1;
    cin >> n >> s1;
    if (n % 2)
    {
        vl pre_od(26), pre_ev(26), suf_od(26), suf_ev(26);

        for (i = n - 1; i >= 0; i--)
        {
            if (i % 2)
                suf_od[s1[i] - 'a']++;
            else
                suf_ev[s1[i] - 'a']++;
        }
        ll ans = n;
        for (i = 0; i < n; i++)
        {
            if (i % 2)
                suf_od[s1[i] - 'a']--;
            else
                suf_ev[s1[i] - 'a']--;
            ll m1 = 0, m2 = 0;
            for (j = 0; j < 26; j++)
            {
                m1 = max(m1, pre_od[j] + suf_ev[j]), m2 = max(m2, pre_ev[j] + suf_od[j]);
            }

            ans = min(ans, (n - 1) - (m1 + m2));
            if (i % 2)
                pre_od[s1[i] - 'a']++;
            else
                pre_ev[s1[i] - 'a']++;
        }

        cout << ans + 1 << endl;
    }
    else
    {
        vl od(26), ev(26);
        for (i = 0; i < n; i++)
        {
            if (i % 2)
                od[s1[i] - 'a']++;
            else
                ev[s1[i] - 'a']++;
        }
        ll m1 = 0, m2 = 0;
        for (i = 0; i < 26; i++)
        {
            m1 = max(m1, od[i]), m2 = max(m2, ev[i]);
        }
        cout << n - (m1 + m2) << endl;
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