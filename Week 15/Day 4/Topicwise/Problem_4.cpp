vector<vector<int>> ans;
int n;

void fun(vector<int> &candidates, vector<int> &temp, int sum, int x, int &target)
{

    if (x == n && sum == target)
    {
        ans.push_back(temp);
        return;
    }
    if (sum > target || x == n)
        return;
    fun(candidates, temp, sum, x + 1, target);
    sum += candidates[x];
    temp.push_back(candidates[x]);
    fun(candidates, temp, sum, x, target);
    fun(candidates, temp, sum, x + 1, target);
    sum -= candidates[x];
    temp.pop_back();
}
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        n = candidates.size();
        vector<int> temp;

        fun(candidates, temp, 0, 0, target);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};