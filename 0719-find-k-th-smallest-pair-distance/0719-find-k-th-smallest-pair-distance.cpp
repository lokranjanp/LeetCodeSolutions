class Solution {
private:
    bool count_pairs(int x, vector<int>&nums, int k)
    {
        const int n = nums.size();
        int count = 0;
        int i = 0;
        for(int j = 1; j<n; ++j)
        {
            while(j>i && nums[j]-nums[i]>x)
                i++;
            count += j-i;
        }
        return (count<k);
    }

public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 0;
        int high = nums.back()-nums[0];

        while(low<high)
        {
            int mid = low+(high-low)/2;

            if(count_pairs(mid, nums, k))
                low = mid+1;
            else
                high = mid;
        }

        return low;
    }
};