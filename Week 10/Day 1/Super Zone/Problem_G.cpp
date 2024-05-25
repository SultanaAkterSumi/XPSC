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
const ll N = 1e5 + 1;
const ll MOD = 1e9 + 7;

void solve()
{
    ll m, i;
    string st;
    cin >> m >> st;
    ll n = 0, s = 0, e = 0, w = 0;
    for (auto it : st)
    {
        if (it == 'N')
            n++;
        else if (it == 'S')
            s++;
        else if (it == 'E')
            e++;
        else
            w++;
    }

    ll diff;
    diff = n - min(n, s);
    if (diff % 2)
    {
        cout << "NO\n";
        return;
    }
    diff = s - min(n, s);
    if (diff % 2)
    {
        cout << "NO\n";
        return;
    }

    diff = e - min(w, e);
    if (diff % 2)
    {
        cout << "NO\n";
        return;
    }
    diff = w - min(w, e);
    if (diff % 2)
    {
        cout << "NO\n";
        return;
    }
    if (m % 2 || n == 1 && s == 1 && e == 0 && w == 0 || n == 0 && s == 0 && e == 1 && w == 1)
    {
        cout << "NO\n";
        return;
    }
    string ans = st;
    ll c;
    c = min(n, s);
    ll n1 = c / 2, n2 = (n - min(n, s)) / 2;
    ll n3 = c - n1;
    ll s1 = c / 2, s2 = (s - min(n, s)) / 2;
    ll s3 = c - s1;
    c = min(e, w);
    ll e1 = c / 2, e2 = (e - min(w, e)) / 2;
    ll e3 = c - e1;
    ll w1 = c / 2, w2 = (w - min(w, e)) / 2;
    ll w3 = c - w1;
    for (i = 0; i < m; i++)
    {
        if (ans[i] == 'N')
        {
            if (n1)
            {
                ans[i] = 'R';
                n1--;
            }
            else if (n3)
            {
                ans[i] = 'H';
                n3--;
            }
            else if (n2)
            {
                ans[i] = 'R';
                n2--;
            }
            else
                ans[i] = 'H';
        }
        else if (ans[i] == 'S')
        {
            if (s1)
            {
                ans[i] = 'R';
                s1--;
            }
            else if (s3)
            {
                ans[i] = 'H';
                s3--;
            }
            else if (s2)
            {
                ans[i] = 'R';
                s2--;
            }
            else
                ans[i] = 'H';
        }
        else if (ans[i] == 'E')
        {
            if (e1)
            {
                ans[i] = 'H';
                e1--;
            }
            else if (e3)
            {
                ans[i] = 'R';
                e3--;
            }
            else if (e2)
            {
                ans[i] = 'R';
                e2--;
            }
            else
                ans[i] = 'H';
        }
        else
        {
            if (w1)
            {
                ans[i] = 'H';
                w1--;
            }
            else if (w3)
            {
                ans[i] = 'R';
                w3--;
            }
            else if (w2)
            {
                ans[i] = 'R';
                w2--;
            }
            else
                ans[i] = 'H';
        }
    }
    cout << ans << endl;
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