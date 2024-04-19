#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        a = abs(a - 1);
        b = abs(b - c);
        b += abs(c - 1);
        if (a < b)
            cout << 1 << endl;
        else if (a > b)
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    return 0;
}