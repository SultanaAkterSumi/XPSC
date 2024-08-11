#include <bits/stdc++.h>
using namespace std;
#define faster               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int main()
{
    faster int t, n, i, a, c1, c2;
    cin >> t;
    while (t--)
    {
        cin >> n;
        c1 = 0;
        c2 = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a;
            if (a == 1)
                c1++;
        }
        if (c1 % 2)
        {
            c2 += ((c1 - 1) / 2);
            c2 += (n - c1 + 1);
        }
        else
        {
            c2 += (c1 / 2);
            c2 += (n - c1);
        }
        cout << c2 << endl;
    }
    return 0;
}