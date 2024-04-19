#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, a;
    string s1;
    vector<char> v1;
    char ch1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cin >> s1;
        for (i = n - 1; i >= 0;)
        {
            if (s1[i] == '0')
            {
                a = (s1[i - 2] - '0') * 10 + (s1[i - 1] - '0');
                a += 96;
                ch1 = a;
                ;
                v1.push_back(ch1);
                i -= 3;
            }
            else
            {
                a = s1[i] - '0';
                a += 96;
                ch1 = a;
                v1.push_back(ch1);
                i -= 1;
            }
        }
        reverse(v1.begin(), v1.end());
        for (auto j : v1)
            cout << j;
        cout << "\n";
        v1.clear();
    }
    return 0;
}