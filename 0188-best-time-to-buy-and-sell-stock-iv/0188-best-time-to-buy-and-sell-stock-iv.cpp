class Solution {
private:
    int calmaxprofit(int ind, int buy, int k, vector<int>& prices,
                     vector<vector<vector<int>>>& dp) {
        if (ind >= prices.size())
            return 0;
        if (k <= 0)
            return 0;
        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];
        int buyallow = -1e9;
        int notbuyallow = -1e9;

        if (buy == 1)
            buyallow =
                max(-prices[ind] + calmaxprofit(ind + 1, 0, k, prices, dp),
                    0 + calmaxprofit(ind + 1, 1, k, prices, dp));
        else
            notbuyallow =
                max(prices[ind] + calmaxprofit(ind + 1, 1, k - 1, prices, dp),
                    0 + calmaxprofit(ind + 1, 0, k, prices, dp));
        return dp[ind][buy][k] = max(buyallow, notbuyallow);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size() + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        // return calmaxprofit(0, 1, k, prices, dp);

        // Tabulation
        int n = prices.size();
        for (int buy = 0; buy <= 1; buy++) {
            for (int j = 0; j <= k; j++) {
                dp[n][buy][j] = 0;
            }
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                dp[ind][buy][0] = 0;
            }
        }
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int K = 1; K <= k; K++) {
                    int buyallow = -1e9;
                    int notbuyallow = -1e9;
                    if (buy == 1) {
                        buyallow = max(-prices[ind] + dp[ind + 1][0][K],
                                       0 + dp[ind + 1][1][K]);
                    } else {
                        notbuyallow = max(prices[ind] + dp[ind + 1][1][K - 1],
                                          0 + dp[ind + 1][0][K]);
                    }
                    dp[ind][buy][K] = max(buyallow, notbuyallow);
                }
            }
        }
        return dp[0][1][k];
    }
};