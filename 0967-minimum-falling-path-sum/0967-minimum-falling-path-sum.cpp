class Solution {
public:
    int dfs(int idx, int i, int n, vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        if(i<0 || i==n)
            return INT_MAX;

        if(idx == n-1)
            return matrix[idx][i];

        if(dp[idx][i]!=-1)
            return dp[idx][i];

        int l = dfs(idx+1,i-1,n,matrix,dp);
        int r = dfs(idx+1,i+1,n,matrix,dp);
        int b = dfs(idx+1,i,n,matrix,dp);

        return dp[idx][i] = matrix[idx][i] + min(l,min(r,b));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        dp[0] = matrix[0];

        for(int i = 1; i<n; ++i)
        {
            for(int j = 0; j<n; ++j)
            {
                int left = 1e9, right = 1e9, down = 1e9;
                if(j>0)
                    left = dp[i-1][j-1];

                down = dp[i-1][j];

                if(j+1<n)
                    right = dp[i-1][j+1];

                dp[i][j] = matrix[i][j] + min(left, min(right, down));
            }

        }

        for(int i = 0; i<dp[0].size(); ++i)
            ans = min(ans, dp[n-1][i]);

        return ans;
    }
};