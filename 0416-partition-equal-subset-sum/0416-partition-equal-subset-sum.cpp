class Solution {
private:
    bool helper(int i, vector<int>&nums, int target, vector<vector<int>>&dp)
    {
        if (i==0)
            return nums[i] == target;

        if(dp[i][target]!=-1)
            return dp[i][target];

        if(target == 0)
            return true;

        if(target<0)
            return false;

        bool skip = helper(i-1, nums, target, dp);
        bool pick = false;
        if(nums[i]<=target)
            pick = helper(i-1, nums, target-nums[i], dp);

        return dp[i][target] = skip || pick;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int n : nums)
            sum += n;

        int n = nums.size();

        if(sum%2!=0)
            return false;

        int target = sum/2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return helper(n-1, nums, target, dp);
    }
};