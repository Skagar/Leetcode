class Solution {
private:
    int countcoins(int ind, int tg, vector<int>& coins,
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

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int tg = amount;
        vector<vector<int>> dp(n, vector<int>(tg + 1, -1));
        dp[n - 1][tg] = countcoins(n - 1, tg, coins, dp);
        long long val = dp[n - 1][tg];
        if (val == 1e9)
            return -1;
        return val;
    }
};