class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mult) {
        priority_queue<pair<long long,int>, vector<pair<long long, int>>, greater<pair<long long, int>>>heap;

        for(int i = 0; i<nums.size(); ++i)
            heap.push({(long long)nums[i], i});

        while(k--){
            auto [val, idx] = heap.top();
            heap.pop();

            val *= mult;
            nums[idx] = val;

            heap.push({val, idx});
        }

        return nums;
    }
};