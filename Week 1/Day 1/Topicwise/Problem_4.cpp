class Solution
{
public:
    long maximumSumSubarray(int K, vector<int> &Arr, int N)
    {
        long ans = 0, i, curr;
        for (i = 0; i < K; i++)
        {
            ans += Arr[i];
        }
        curr = ans;
        long j = 0;
        for (; i < N; i++, j++)
        {
            curr = (curr + Arr[i] - Arr[j]);
            ans = max(ans, curr);
        }
        return ans;
    }
};