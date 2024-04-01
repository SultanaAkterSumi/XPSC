#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    ll t, n, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> v1(n);
        ll sum = 0;
        for (i = 0; i < n; i++)
        {
            cin >> v1[i];
            if (v1[i] < 0)
                sum += (-1 * v1[i]);
            else
                sum += v1[i];
        }
        bool flag = false;
        ll operation = 0;
        for (i = 0; i < n; i++)
        {
            if (v1[i] < 0 && flag == false)
            {
                operation++;
                flag = true;
            }
            else if (flag == true)
            {
                if (v1[i] > 0)
                    flag = false;
            }
        }

        cout << sum << " " << operation << endl;
        v1.clear();
    }
    return 0;
}