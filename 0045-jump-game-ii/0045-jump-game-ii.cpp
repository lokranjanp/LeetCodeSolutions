class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i = 1; i<nums.size(); ++i)
        {
            nums[i] = max(nums[i]+i, nums[i-1]);
        }

        int res = 0, i = 0;

        while(i<nums.size()-1)
        {
            res++;
            i = nums[i];
        }

        return res;
    }
};