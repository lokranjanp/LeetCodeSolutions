class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1 && nums[0]==0)
            return;
        int i = 0; 
        int j;
        for(j=0;j<nums.size();j++)
            if(nums[j]==0)
                break;

        
        for(i = j+1; i<nums.size(); i++)
        {
            if(nums[i]!=0)
            {    swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};