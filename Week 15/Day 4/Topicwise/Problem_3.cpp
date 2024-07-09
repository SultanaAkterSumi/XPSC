vector<vector<int>> ans;
int n;
void fun(vector<int> &nums, vector<int> &temp, int x)
{
    if (x == n)
    {
        ans.push_back(temp);
        return;
    }
    fun(nums, temp, x + 1);
    temp.push_back(nums[x]);
    fun(nums, temp, x + 1);
    temp.pop_back();
}
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        ans.clear();
        sort(nums.begin(), nums.end());
        n = nums.size();
        vector<int> temp;
        fun(nums, temp, 0);
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};