class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_map<int,int> hash;

        for(int i = 1; i<nums.size(); i++)
        {
            int sum = nums[i-1] + nums[i];
            if(hash.find(sum)!=hash.end())
                return true;

            hash[sum]++;
        }
        return false;
    }
};