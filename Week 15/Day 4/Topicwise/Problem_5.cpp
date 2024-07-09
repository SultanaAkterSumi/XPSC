
vector<vector<int>> ans;
int n;

void fun(vector<int> &candidates, vector<int> &temp, int sum, int x, int &target)
{

    if (sum == target)
    {
        ans.push_back(temp);
        return;
    }
    if (sum > target || x == n)
        return;
    int i;
    for (i = x; i < n; i++)
    {
        if (i > x && candidates[i - 1] == candidates[i])
            continue;
        sum += candidates[i];
        temp.push_back(candidates[i]);
        fun(candidates, temp, sum, i + 1, target);
        sum -= candidates[i];
        temp.pop_back();
    }
}
class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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