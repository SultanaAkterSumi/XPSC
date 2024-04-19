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
    int s = 0, e = n; // s=starting point,e=ending point
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (A[mid] == key)
        {
            return mid;
        }
        else if (key < A[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
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
        if (Binary(A, n, key) < 0)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}