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
#define yes cout << "YES\n";
#define no cout << "NO\n";
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
const ll N = 1e10;
vector<string> col = {"BG", "BR", "BY", "GR", "GY", "RY"};
void solve()
{
    ll n, q, i, j;
    string s1, s2, s3;
    cin >> n >> q;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> s1;
        v1[i] = find(col.begin(), col.end(), s1) - col.begin();
    }
    vl v2(6, -1);
    vector<vl> nl(n);
    for (i = 0; i < n; i++)
    {
        v2[v1[i]] = i;
        nl[i] = v2;
    }
    v2.assign(6, -1);
    vector<vl> nr(n);
    for (i = n - 1; i >= 0; i--)
    {
        v2[v1[i]] = i;
        nr[i] = v2;
    }
    while (q--)
    {
        cin >> i >> j;
        i--, j--;
        if (i > j)
            swap(i, j);
        s1 = col[v1[i]], s2 = col[v1[j]];
        if (s1[0] == s2[0] || s1[0] == s2[1] || s1[1] == s2[0] || s1[1] == s2[1])
            cout << j - i << endl;
        else
        {
            ll ans1 = N, ans2 = N, ans3 = N, ans4 = N;
            s3.clear();
            s3.push_back(s1[0]);
            s3.push_back(s2[0]);
            sort(s3.begin(), s3.end());
            ll t1 = find(col.begin(), col.end(), s3) - col.begin();
            ll left = nl[i][t1];
            if (left != -1)
            {
                ans1 = i - left + j - left;
            }
            ll right = nr[i][t1];
            if (right != -1)
            {
                ans1 = min(ans1, right - i + abs(j - right));
            }

            s3.clear();
            s3.push_back(s1[0]);
            s3.push_back(s2[1]);
            sort(s3.begin(), s3.end());
            t1 = find(col.begin(), col.end(), s3) - col.begin();
            left = nl[i][t1];
            if (left != -1)
            {
                ans2 = i - left + j - left;
            }
            right = nr[i][t1];
            if (right != -1)
            {
                ans2 = min(ans2, right - i + abs(j - right));
            }

            s3.clear();
            s3.push_back(s1[1]);
            s3.push_back(s2[0]);
            sort(s3.begin(), s3.end());
            t1 = find(col.begin(), col.end(), s3) - col.begin();
            left = nl[i][t1];
            if (left != -1)
            {
                ans3 = i - left + j - left;
            }
            right = nr[i][t1];
            if (right != -1)
            {
                ans3 = min(ans3, right - i + abs(j - right));
            }

            s3.clear();
            s3.push_back(s1[1]);
            s3.push_back(s2[1]);
            sort(s3.begin(), s3.end());
            t1 = find(col.begin(), col.end(), s3) - col.begin();
            left = nl[i][t1];
            if (left != -1)
            {
                ans4 = i - left + j - left;
            }
            right = nr[i][t1];
            if (right != -1)
            {
                ans4 = min(ans4, right - i + abs(j - right));
            }
            ll ans = min({ans1, ans2, ans3, ans4});
            if (ans == N)
                ans = -1;
            cout << ans << endl;
        }
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