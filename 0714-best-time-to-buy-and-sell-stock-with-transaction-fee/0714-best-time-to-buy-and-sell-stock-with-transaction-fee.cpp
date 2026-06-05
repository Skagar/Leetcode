class Solution {
    int calmaxprofit(int ind, int buy, int fee, vector<int>& prices,
                     vector<vector<int>>& dp) {
        if (ind >= prices.size())
            return 0;
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        int buyallow = -1e9;
        int notbuyallow = -1e9;
        if (buy == 1) {
            buyallow =
                max(-prices[ind] + calmaxprofit(ind + 1, 0, fee, prices, dp),
                    0 + calmaxprofit(ind + 1, 1, fee, prices, dp));
        } else {
            notbuyallow = max(prices[ind] - fee +
                                  calmaxprofit(ind + 1, 1, fee, prices, dp),
                              0 + calmaxprofit(ind + 1, 0, fee, prices, dp));
        }
        return dp[ind][buy] = max(buyallow, notbuyallow);
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return calmaxprofit(0, 1, fee, prices, dp);
    }
};