typedef long long ll;
class Solution
{
public:
    int longestKSubstr(string s, int k)
    {
        ll n = s.size(), i, j, ans = -1;
        string s1 = s;
        i = 0;
        j = 0;
        map<char, ll> m1;
        while (j < n)
        {
            m1[s1[j]]++;
            while (m1.size() > k)
            {
                m1[s1[i]]--;
                if (m1[s1[i]] == 0)
                    m1.erase(s1[i]);
                i++;
            }
            if (m1.size() == k)
                ans = max(ans, (j - i + 1));
            // cout << (j - i + 1) << endl;
            j++;
        }
        return ans;
    }
};