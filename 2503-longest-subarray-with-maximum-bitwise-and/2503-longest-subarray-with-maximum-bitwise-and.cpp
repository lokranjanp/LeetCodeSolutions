class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();

        int maxlen = INT_MIN;
        int max_ind = max_element(nums.begin(), nums.end()) - nums.begin();
        int max_ele = nums[max_ind];

        for(int i = max_ind; i<n; i++)
        {
            int res = 0;

            while(i<n && nums[i] == max_ele)
            {
                i++;
                res++;
            }

            maxlen = max(maxlen, res);
        }

        return maxlen;
    }
};