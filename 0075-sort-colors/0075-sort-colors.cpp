class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size()-1;

        for(int i = 0; i<nums.size(); i++)
        {
            while(i>=low && i<=high && (nums[i] == 0||nums[i] == 2)){
                if(nums[i] == 0)
                    swap(nums[i], nums[low++]);
                else if(nums[i] == 2)
                    swap(nums[i], nums[high--]);
            }
        }
    }
};