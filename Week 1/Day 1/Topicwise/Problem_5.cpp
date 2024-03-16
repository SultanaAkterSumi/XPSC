typedef long long ll;
typedef vector<ll> vl;
class Solution
{
public:
    int search(string pat, string txt)
    {
        ll ans = 0, i;
        char ch;
        vl v1(26, 0), v2(26, 0), v3(26, 0), v4(26, 0);
        for (auto it : pat)
        {
            if (it >= 'A' && it <= 'Z')
                v1[it - 'A']++;
            else
                v2[it - 'a']++;
        }
        ll t1 = pat.size();

        for (i = 0; i < t1; i++)
        {
            ch = txt[i];
            if (ch >= 'A' && ch <= 'Z')
                v3[ch - 'A']++;
            else
                v4[ch - 'a']++;
        }

        if (v1 == v3 && v2 == v4)
            ans++;
        t1 = txt.size();
        ll t2 = 0;
        for (; i < t1; i++, t2++)
        {
            ch = txt[i];
            if (ch >= 'A' && ch <= 'Z')
                v3[ch - 'A']++;
            else
                v4[ch - 'a']++;
            ch = txt[t2];
            if (ch >= 'A' && ch <= 'Z')
                v3[ch - 'A']--;
            else
                v4[ch - 'a']--;
            if (v1 == v3 && v2 == v4)
                ans++;
        }
        return ans;
    }
};