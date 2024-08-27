class Solution {
private:
    int helper(int i, int target, vector<vector<int>>&dp, vector<int>&nums)
    {
        if(target == 0)
            return 0;

        if(target < 0)
            return INT_MIN;

        if(i >= nums.size())
            return INT_MIN;

        if(dp[i][target]!=-1)
            return dp[i][target];

        int pick = 1 + helper(i+1, target-nums[i], dp, nums);
        int skip = helper(i+1, target, dp, nums);

        return dp[i][target] = max(pick, skip);
    }

public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));

        int res = helper(0, target, dp, nums);
        if(res <= 0)
            return -1;
        
        return res;
    }
};