class Solution {
public:
    static bool comp_op(pair<int,int>&p1, pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto n : nums)
            mpp[n]++;

        vector<pair<int,int>>cont;
        vector<int>ans;

        for(auto x : mpp)
            cont.push_back({x.first, x.second});
        
        sort(cont.begin(), cont.end(), comp_op);

        for(int i = 0; i<k; ++i)
            ans.push_back(cont[i].first);

        return ans;
    }
};