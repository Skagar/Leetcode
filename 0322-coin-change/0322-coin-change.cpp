class Solution {
private:
    // MEMOIZATION
    /*int countcoins(int ind, int tg, vector<int>& coins,
                   vector<vector<int>>& dp) {
        if (tg == 0)
            return 0;
        if (ind == 0) {
            if (tg % coins[ind] == 0)
                return tg / coins[ind];
            else
                return 1e9;
        }
        if (dp[ind][tg] != -1)
            return dp[ind][tg];
        int tk = INT_MAX;
        int ntk = INT_MAX;
        ntk = 0 + countcoins(ind - 1, tg, coins, dp);
        if (coins[ind] <= tg)
            tk = 1 + countcoins(ind, tg - coins[ind], coins, dp);
        dp[ind][tg] = min(tk, ntk);
        return dp[ind][tg];
    }
*/
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int tg = amount;
        vector<vector<int>> dp(n, vector<int>(tg + 1, -1));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= tg; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int target = 0; target <= tg; target++) {
                int tk = INT_MAX;
                int ntk = INT_MAX;
                ntk = 0 + dp[ind - 1][target];
                if (coins[ind] <= target)
                    tk = 1 + dp[ind][target - coins[ind]];
                dp[ind][target] = min(tk, ntk);
            }
        }
        if (dp[n - 1][tg] == 1e9)
            return -1;
        else
            return dp[n - 1][tg];
    }
};