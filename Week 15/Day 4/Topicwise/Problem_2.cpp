vector<vector<string>> ans;
string s1;
int sz;
void fun(vector<string> &temp, string &curr, int x)
{
    for (auto it : temp)
        cout << it << ' ';
    cout << endl;
    cout << curr << endl
         << x << endl;
    if (x == sz)
    {
        if (!temp.empty() && curr.empty())
            ans.push_back(temp);

        return;
    }

    int i, j;
    for (j = x; j < sz; j++)
    {
        curr.push_back(s1[j]);
        int m = curr.size();
        bool f = true;
        for (i = 0; i < m / 2; i++)
        {
            if (curr[i] != curr[m - 1 - i])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            temp.push_back(curr);
            curr.clear();
            fun(temp, curr, j + 1);
            curr = temp.back();
            temp.pop_back();
        }
    }
}
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        ans.clear();
        s1 = s;
        sz = s.size();
        vector<string> temp;
        string curr;
        fun(temp, curr, 0);
        return ans;
    }
};