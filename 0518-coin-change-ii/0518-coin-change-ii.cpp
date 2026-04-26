class Solution {
    int change(int ind, int tg, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (tg % coins[ind] == 0) {
                return 1;
            } else
                return 0;
        }
        if (dp[ind][tg] != -1)
            return dp[ind][tg];
        int tk = 0;
        int ntk = 0;
        ntk = ntk + change(ind - 1, tg, coins, dp);
        if (coins[ind] <= tg)
            tk = tk + change(ind, tg - coins[ind], coins, dp);
        return dp[ind][tg] = ntk + tk;
    }

public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int tg = amount;
        vector<vector<int>> dp(n, vector<int>(tg + 1, -1));
        return change(n - 1, tg, coins, dp);
    }
};