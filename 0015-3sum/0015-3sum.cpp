class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int target = 0;
        if(nums.size()<3)
            return ans;

        set<vector<int>> res;
        sort(nums.begin(),nums.end());

        for(int i = 0; i<nums.size(); i++)
        {
            int j =i+1;
            int k = nums.size()-1;

            while(j<k)
            {
                int sum = nums[i]+nums[k]+nums[j];

                if(sum == target)
                {    
                    res.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }

                else if(sum<target)
                    j++;

                else
                    k--;
            }
        }

        for(auto num: res)
            ans.push_back(num);

        return ans;
    }
};