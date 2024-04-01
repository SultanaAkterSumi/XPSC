#include <bits/stdc++.h>
using namespace std;
#define faster               \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define ll long long
int main()
{
    faster int T;
    cin >> T;
    string s1, s2;
    ll i, l1, l2, l3, l4;
    while (T--)
    {
        cin >> s1 >> s2;
        l1 = s1.size();
        l2 = s2.size();
        if (s1 == s2)
            cout << "=\n";
        else
        {
            if (s1[l1 - 1] == 'S' && s2[l2 - 1] == 'M')
                cout << "<\n";
            else if (s1[l1 - 1] == 'M' && s2[l2 - 1] == 'S')
                cout << ">\n";
            else if (s1[l1 - 1] == 'S' && s2[l2 - 1] == 'L')
                cout << "<\n";
            else if (s1[l1 - 1] == 'L' && s2[l2 - 1] == 'S')
                cout << ">\n";
            else if (s1[l1 - 1] == 'M' && s2[l2 - 1] == 'L')
                cout << "<\n";
            else if (s1[l1 - 1] == 'L' && s2[l2 - 1] == 'M')
                cout << ">\n";
            else
            {
                if (s1[l1 - 1] == 'S')
                {
                    l3 = 0;
                    l4 = 0;
                    for (i = 0; i < (l1 - 1); i++)
                    {
                        if (s1[i] == 'X')
                            l3++;
                    }
                    for (i = 0; i < (l2 - 1); i++)
                    {
                        if (s2[i] == 'X')
                            l4++;
                    }
                    if (l3 < l4)
                        cout << ">\n";
                    else if (l3 > l4)
                        cout << "<\n";
                    else
                        cout << "=\n";
                }
                else
                {
                    l3 = 0;
                    l4 = 0;
                    for (i = 0; i < (l1 - 1); i++)
                    {
                        if (s1[i] == 'X')
                            l3++;
                    }
                    for (i = 0; i < (l2 - 1); i++)
                    {
                        if (s2[i] == 'X')
                            l4++;
                    }
                    if (l3 < l4)
                        cout << "<\n";
                    else if (l3 > l4)
                        cout << ">\n";
                    else
                        cout << "=\n";
                }
            }
        }
    }
    return 0;
}