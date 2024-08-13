class Solution {
public:
    void findAns(int index, int target, vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr) {
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            if(i > index && nums[i] ==nums[i-1]) continue;
            if(nums[i] > target) break;
            curr.push_back(nums[i]);
            findAns(i+1, target-nums[i], nums, ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> helper;
        findAns(0, target, candidates, ans, helper);
        return ans;
    }
};