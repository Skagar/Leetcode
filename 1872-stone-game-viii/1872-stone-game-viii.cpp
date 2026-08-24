class Solution {
    int calmax(int ind, vector<int>& prefixsum, vector<int>& dp) {
        if (ind == prefixsum.size() - 1)
            return prefixsum[ind];
        if (dp[ind] != -1)
            return dp[ind];
        int tk = prefixsum[ind] - calmax(ind + 1, prefixsum, dp);
        int ntk = calmax(ind + 1, prefixsum, dp);
        return dp[ind] = max(tk, ntk);
    }

public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dp(n + 1, -1);
        vector<int> prefixsum(n);
        prefixsum[0] = stones[0];
        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + stones[i];
        }
        // return calmax(1, prefixsum, dp);
        dp[n - 1] = prefixsum[n - 1];
        for (int ind = n - 2; ind >= 1; ind--) {
            int tk = prefixsum[ind] - dp[ind + 1];
            int ntk = dp[ind + 1];
            dp[ind] = max(tk, ntk);
        }
        return dp[1];
    }
};