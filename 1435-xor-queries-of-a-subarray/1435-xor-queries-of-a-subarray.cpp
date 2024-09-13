class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans(queries.size());
        int n = arr.size();
        vector<int>pref(n);

        pref[0] = arr[0];
        for(int i = 1; i<n; i++)
            pref[i] = pref[i-1]^arr[i];

        for(int i =0; i<queries.size(); i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];

            if(left == 0)
                ans[i] = pref[right];
            else
                ans[i] = pref[right]^pref[left-1];
        }

        return ans;
    }
};