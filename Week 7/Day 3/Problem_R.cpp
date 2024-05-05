#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
typedef long long ll;
typedef vector<ll> vl;
#define yes cout << "YES\n";
#define no cout << "NO\n";

vector<pair<ll, char>> ins;
set<ll> ans;
vector<set<ll>> step(1009);
ll n, m;
void fun(ll i, ll curr)
{
    if (i == m)
    {
        ans.insert(curr);
        return;
    }
    if (step[i].count(curr))
        return;
    if (ins[i].second == '?')
    {
        ll t1, t2;
        t1 = ins[i].first % n;
        if (n - curr < t1)
            t1 = t1 - (n - curr);
        else
            t1 = curr + t1;

        fun(i + 1, t1);

        t2 = ins[i].first % n;
        if (curr - 1 < t2)
            t2 = n - (t2 - curr);
        else
            t2 = curr - t2;

        fun(i + 1, t2);
    }
    else
    {
        ll t1;
        if (ins[i].second == '0')
        {
            t1 = ins[i].first;
            if (n - curr < t1)
                t1 = t1 - (n - curr);
            else
                t1 = curr + t1;
        }
        else
        {
            t1 = ins[i].first;
            if (curr - 1 < t1)
                t1 = n - (t1 - curr);
            else
                t1 = curr - t1;
        }
        fun(i + 1, t1);
    }
    step[i].insert(curr);
}
void solve()
{
    ins.clear();
    ans.clear();

    ll i, x;
    cin >> n >> m >> x;

    for (i = 0; i < m; i++)
    {
        pair<ll, char> p1;
        cin >> p1.first >> p1.second;

        ins.push_back(p1);
        step[i].clear();
    }
    fun(0, x);
    cout << ans.size() << endl;
    for (auto it : ans)
        cout << it << ' ';
    cout << endl;
}
int main()
{
    op() int tc = 1;
    // Sieve();
    cin >> tc;
    // cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout<<"Case "<<t<<": ";
        // cout<<"Scenario #"<<t<<": ";
        solve();
    }
}