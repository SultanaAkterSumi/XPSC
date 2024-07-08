vector<vector<int>> ans;
vector<int> v1;
int n;
void fun(vector<bool> &vis, vector<int> &curr)
{
    if (curr.size() == n)
    {
        ans.push_back(curr);
        return;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            curr.push_back(v1[i]);
            vis[i] = true;
            fun(vis, curr);
            curr.pop_back();
            vis[i] = false;
        }
    }
}
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        ans.clear();
        v1.clear();
        n = 0;
        for (auto it : nums)
        {
            v1.push_back(it);
            n++;
        }
        vector<bool> vis(n, false);
        vector<int> curr;
        fun(vis, curr);
        return ans;
    }
};