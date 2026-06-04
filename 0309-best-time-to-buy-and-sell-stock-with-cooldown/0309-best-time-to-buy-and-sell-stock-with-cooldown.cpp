class Solution {
    int calmaxprofit(int ind, int buy, vector<int>& prices,
                     vector<vector<int>>& dp) {
        if (ind >= prices.size()) {
            return 0;
        }
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int buyallow = -1e9;
        int notbuy = -1e9;
        if (buy == 1) {
            buyallow = max(-prices[ind] + calmaxprofit(ind + 1, 0, prices, dp),
                           0 + calmaxprofit(ind + 1, 1, prices, dp));
        } else {
            notbuy = max(prices[ind] + calmaxprofit(ind + 2, 1, prices, dp),
                         0 + calmaxprofit(ind + 1, 0, prices, dp));
        }
        return dp[ind][buy] = max(buyallow, notbuy);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return calmaxprofit(0, 1, prices, dp);
    }
};