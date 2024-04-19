#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

#define op()                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define sza(x) (x.size())
#define f first
#define sc second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define endl '\n'
#define sp " "
#define pb push_back
#define test   \
    ll tc;     \
    cin >> tc; \
    while (tc--)
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
#define printm(a)                       \
    {                                   \
        for (auto u : a)                \
            cout << u.f sp u.s << endl; \
    }
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))
#define PI 2.0 * acos(0.0) // 3.1415926535897932384626433832795l
#define Dpos(n) fixed << setprecision(n)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll>::iterator vit;
typedef set<ll> sll;
typedef map<ll, ll> mll;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

/*
vector<vl>v3(1000);
vector<vector<bool>>Visited(1000);
ll n,m,x,sum=0;
void DFS(ll i,ll j){
 // cout<<i<<sp<<j<<sp<<v3[i][j]<<endl;
  Visited[i][j]=true;
  vector<pll>temp;
  temp.push_back({i-1,j});
  temp.push_back({i+1,j});
  temp.push_back({i,j-1});
  temp.push_back({i,j+1});
  x+=v3[i][j];
  //cout<<x<<endl;
  for(auto it:temp){
    if(it.first>=0&&it.first<n&&it.second>=0&&it.second<m){
  if(!Visited[it.first][it.second]){
      //x+=v3[it.first][it.second];
      DFS(it.first,it.second);
    }
    }
    }
    sum=max(sum,x);
} */
/*ll Binary_Search(const vl &v1, ll n, ll x){
  ll low=0, high=n-1,mid,res=0;
  while(low<=high){
      mid=(low+high)/2;
      if(v1[mid]==x) return (mid+1);
      if(v1[mid]<x){
        res=mid+1;
        low=mid+1;
      }
      else {
      high=mid-1;}

  }
  return res;
}*/
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }

bool cmp(const pair<char, ll> &a, const pair<char, ll> &b)
{

    // if(a.first != b.first){
    return a.second < b.second;
    //}
    // else
    // return a.second<b.second;
}
bool cmp1(const pair<ll, ll> &a, const pair<ll, ll> &b)
{

    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    else
        return a.second < b.second;
}
ll fun(ll n)
{
    ll low = 2, high = 10000000000, mid, res = 2;
    while (low <= high)
    {
        mid = (low + high) / 2;
        ll temp = mid * (mid - 1) / 2;
        if (temp == n)
            return mid;
        if (temp < n)
        {
            res = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return res;
}
// Sieve
bool isprime[1009];
void Sieve()
{
    memset(isprime, true, sizeof(isprime));
    ll i, j, limit = sqrt(1009 * 1.) + 2;
    isprime[1] = false;
    for (i = 4; i < 1009; i += 2)
        isprime[i] = false;
    for (i = 3; i < 1009; i += 2)
    {
        if (isprime[i])
        {
            if (i < limit)
            {
                for (j = i * i; j < 1009; j += i * 2)
                    isprime[j] = false;
            }
        }
    }
}
ll Binary_Search(const vl &v1, ll n, ll x)
{
    ll low = 0, high = n - 1, mid, res = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v1[mid] <= x)
        {
            res = mid + 1;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
void solve()
{
    ll n, m, i, num;
    cin >> n;
    vl v1(n);
    for (i = 0; i < n; i++)
        cin >> v1[i];
    sort(v1.begin(), v1.end());
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> num;
        cout << Binary_Search(v1, n, num) << endl;
    }
}

int main()
{
    op()
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int tc = 1;
    Sieve();
    // cin >> tc;
    // cin.ignore();
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case " << t << ": ";
        solve();
    }
}