class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> res;

        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum += nums[j];
                res.push_back(sum);
            }
        }

        sort(res.begin(), res.end());

        int ans = 0;
        int MOD = 1000000007;

        for (int i = left - 1; i < right; ++i) 
            ans = (ans + res[i]) % MOD;
        
        return ans;
    }
};