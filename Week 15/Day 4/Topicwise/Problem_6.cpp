vector<vector<string>> ans;
string s;
int n;
void fun(vector<pair<int, int>> &temp, int x)
{
    if (x > n)
    {
        vector<string> temp1;
        for (auto it : temp)
        {
            s.clear();
            int i;
            for (i = 1; i <= n; i++)
            {
                if (it.second == i)
                    s.push_back('Q');
                else
                    s.push_back('.');
            }
            temp1.push_back(s);
        }
        ans.push_back(temp1);
        return;
    }
    int i;
    for (i = 1; i <= n; i++)
    {
        pair<int, int> p = {x, i};
        bool f = true;
        for (auto it : temp)
        {
            if (it.second == i || abs(it.first - p.first) == abs(it.second - p.second))
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            temp.push_back(p);
            fun(temp, x + 1);
            temp.pop_back();
        }
    }
}
class Solution
{
public:
    vector<vector<string>> solveNQueens(int m)
    {
        n = m;
        ans.clear();
        vector<pair<int, int>> temp;
        fun(temp, 1);
        return ans;
    }
};