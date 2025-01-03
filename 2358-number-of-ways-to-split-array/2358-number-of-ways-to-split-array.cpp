class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long leftsum = 0, rightsum = 0;

        for(int n : nums)
            rightsum += n;

        int split_count = 0;

        for(int i = 0; i<n-1; i++)
        {
            leftsum += nums[i];
            rightsum -= nums[i];

            if(leftsum >= rightsum)
                split_count++;
        }

        return split_count;
    }
};