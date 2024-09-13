class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int n = arr.size();

        for(int i =0; i<queries.size(); i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];

            int xor_res = arr[left];
            for(int j = left+1; j<right+1; j++)
                xor_res = xor_res ^ arr[j];
            
            ans.push_back(xor_res);
        }

        return ans;
    }
};