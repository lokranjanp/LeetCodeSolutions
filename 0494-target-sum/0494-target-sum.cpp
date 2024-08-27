class Solution {
public:
    int helper(int ind, vector<int>&nums,int target, int n)
    {
        if(ind == n)
        {
            if(target == 0)
            {
                return 1;
            }
            return 0;
        }

        int pos = helper(ind+1, nums, target-nums[ind], n);
        int neg = helper(ind+1, nums, target+nums[ind], n);

        return pos+neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        return helper(0,nums,target,nums.size());
    }
};