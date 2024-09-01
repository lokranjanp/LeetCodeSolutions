class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& orig, int m, int n) {
        if(m * n != orig.size())
            return {};

        vector<vector<int>>ans(m, vector<int>(n, 0));
        int x = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; ++j)
                ans[i][j] = orig[x++];
        }
        return ans;
    }
};