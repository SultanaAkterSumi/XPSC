#include <bits/stdc++.h>
using namespace std;
#define faster               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
#define ul unsigned long long
int Binary(int A[], ll n, ll key)
{
    int s = -1, e = n;
    if (key <= A[0])
        return 0;
    else if (key > A[n - 1])
        return n;
    else if (key == A[n - 1])
        return n - 1; // s=starting point,e=ending point
    while (1)
    {
        int mid = (s + e) / 2;
        if (s + 1 >= e)
            return e;
        else if (key <= A[mid])
        {
            e = mid;
        }
        else
        {
            s = mid;
        }
    }
}
int main()
{
    faster
#ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, k, i, key;
    cin >> n >> k;
    int A[n];
    for (i = 0; i < n; i++)
    {
        cin >> A[i]; // ascending order
    }
    while (k--)
    {
        cin >> key;
        int ans = Binary(A, n, key);
        cout << ans + 1 << endl;
    }
    return 0;
}