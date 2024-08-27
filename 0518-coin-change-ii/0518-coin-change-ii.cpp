class Solution {
private:
    int helper(int i, int amnt, vector<int>&coins, vector<vector<int>>&dp)
    {
        if(i>=coins.size())
            return 0;

        if(amnt == 0)
            return 1;

        if(dp[i][amnt]!=-1)
            return dp[i][amnt];

        int notpick = helper(i+1, amnt, coins, dp);

        int pick = 0;
        if(amnt >= coins[i])
            pick = helper(i, amnt-coins[i], coins, dp);

        return dp[i][amnt] = pick + notpick;
    }

public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int n = coins.size();

        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return helper(0, amount, coins, dp);
    }
};