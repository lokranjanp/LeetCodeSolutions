class Solution {
private:
    void mergesort(vector<int>&nums, int left, int mid, int right)
    {
        int low = left;
        int high = mid+1;
        vector<int> temp;

        while(low<=mid && high<=right)
        {
            if(nums[low]<=nums[high])
            {
                temp.push_back(nums[low]);
                low++;
            }
            else
            {
                temp.push_back(nums[high]);
                high++;
            }
        }

        while(low<=mid)
        {
            temp.push_back(nums[low]);
            low++; 
        }

        while(high<=right)
        {
            temp.push_back(nums[high]);
            high++;
        }

        for(int i = left; i<=right; i++)
            nums[i] = temp[i-left];
    }

    void split(vector<int>&nums, int left, int right)
    {
        if(left >= right)
            return;

        int mid = left + (right - left)/2;
        split(nums, left, mid);
        split(nums, mid+1, right);
        mergesort(nums, left, mid, right);
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        split(nums, 0, nums.size()-1);
        return nums;
    }
};