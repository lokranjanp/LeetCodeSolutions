class Solution {
private:
    int helper(vector<int>&nums, int i, int start, vector<int>&dp)
    {
        if(i<start)
            return 0;

        if(i == start)
            return nums[start];

        if(dp[i]!=-1)
            return dp[i];

        int rob = nums[i] + helper(nums, i-2, start, dp);
        int skiprob = helper(nums, i-1, start, dp);

        return dp[i] = max(rob, skiprob);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return nums[0];

        if(n==2)
            return max(nums[0], nums[1]);

        vector<int>dp1(n,-1);
        int first = helper(nums, n-2, 0, dp1);

        vector<int>dp2(n,-1);
        int last = helper(nums, n-1, 1, dp2);

        return max(first, last);
    }
};