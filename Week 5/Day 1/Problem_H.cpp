#include <bits/stdc++.h>
using namespace std;
#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define sz(x) (x.size())
#define fr first
#define sc second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
#define sp " "
#define fora(a) for (auto u : a)
#define forn(i, n) for (auto i = 0; i < n; i++)
#define af(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define printv(a)             \
    {                         \
        for (auto u : a)      \
            cout << u << " "; \
        cout << endl;         \
    }
#define printm(a)                               \
    {                                           \
        for (auto u : a)                        \
            cout << u.fr << sp << u.sc << endl; \
    }
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0) // 3.1415926535897932384626433832795l
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define Dpos(n) fixed << setprecision(n)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<ll>::iterator vit;
typedef set<ll> sll;
typedef map<ll, ll> mll;
typedef pair<ll, ll> pll;
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
// customized priority queue
struct cmp
{
    // priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp>pq;
    bool operator()(pair<ll, ll> p1, pair<ll, ll> p2)
    {
        if (p1.second - p1.first != p2.second - p2.first)
            return p1.second - p1.first < p2.second - p2.first;
        return p1.first > p2.first; // if want p1.first<p2.first
    }
};

void solve()
{
    ll n, i, sum = 0, neg = 0;
    bool f1 = false;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> v1[i];
        if (v1[i] < 0)
            neg++;
        else if (v1[i] == 0)
            f1 = true;
    }
    if (neg % 2 == 0 || f1)
    {
        for (i = 0; i < n; i++)
        {
            sum += abs(v1[i]);
        }
    }
    else
    {
        for (i = 0; i < n; i++)
            v1[i] = abs(v1[i]);
        sort(v1.begin(), v1.end());
        sum += (v1[0] * -1);
        for (i = 1; i < n; i++)
        {
            sum += v1[i];
        }
    }
    cout << sum << endl;
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