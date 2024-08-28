class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = INT_MIN;
        int n = prices.size();
        int minprice = INT_MAX;

        for(int i = 0; i<n; i++)
        {
            minprice = min(minprice, prices[i]);
            maxprofit = max(maxprofit, prices[i]-minprice);
        }

        return maxprofit;
    }
};