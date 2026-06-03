class Solution {
private:
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
            notbuy = max(prices[ind] + calmaxprofit(ind + 1, 1, prices, dp),
                         0 + calmaxprofit(ind + 1, 0, prices, dp));
        }
        return dp[ind][buy] = max(buyallow, notbuy);
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, -1));
        /* int val = calmaxprofit(0, 1, prices, dp);
         return val;*/
        int n = prices.size();
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 1; buy >= 0; buy--) {
                int buyallow = -1e9;
                int notbuy = -1e9;
                if (buy == 1) {
                    buyallow =
                        max(-prices[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
                } else {
                    notbuy =
                        max(prices[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
                }
                dp[ind][buy] = max(buyallow, notbuy);
            }
        }
        return dp[0][1];
    }
};