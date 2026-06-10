class Solution {
    int calmaxprofit(int ind, int buy, int k, int& n, vector<int>& prices,
                     vector<vector<vector<int>>>& dp) {
        if (ind >= n)
            return 0;
        if (k < 0)
            return 0;
        if (dp[ind][buy][k] != -1)
            return dp[ind][buy][k];
        int buyallow = -1e9;
        int notbuyallow = -1e9;
        if (buy == 1) {
            buyallow =
                max(-prices[ind] + calmaxprofit(ind + 1, 0, k, n, prices, dp),
                    0 + calmaxprofit(ind + 1, 1, k, n, prices, dp));
        } else {
            notbuyallow = max(
                prices[ind] + calmaxprofit(ind + 1, 1, k - 1, n, prices, dp),
                0 + calmaxprofit(ind + 1, 0, k, n, prices, dp));
        }
        return dp[ind][buy][k] = max(buyallow, notbuyallow);
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(2, -1)));
        return calmaxprofit(0, 1, 1, n, prices, dp);
    }
};