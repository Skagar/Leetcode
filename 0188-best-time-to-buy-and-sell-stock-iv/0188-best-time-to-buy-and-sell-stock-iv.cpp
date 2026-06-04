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
        return dp[ind][buy][k]=max(buyallow, notbuyallow);
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size(), vector<vector<int>>(2, vector<int>(k + 1, -1)));
        return calmaxprofit(0, 1, k, prices, dp);
    }
};