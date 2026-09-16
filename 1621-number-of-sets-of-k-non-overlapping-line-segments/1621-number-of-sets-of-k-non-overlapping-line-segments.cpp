class Solution {
private:
    long long calways(int& n, int k, int ind, long long& m,
                      vector<vector<long long>>& dp) {
        if (ind >= n)
            return 0;
        if (k == 0)
            return 1;
        if (dp[ind][k] != -1)
            return dp[ind][k];
        long long skip = 0LL;
        long long take = 0LL;
        skip = calways(n, k, ind + 1, m, dp) % m;
        for (int j = ind + 1; j < n; j++) {
            take = take % m + calways(n, k - 1, j, m, dp) % m;
        }
        return dp[ind][k] = (skip % m + take % m) % m;
    }

public:
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));
        long long m = 1e9 + 7;
        // return calways(n, k, 0, m, dp);
        for (int ind = 0; ind < n; ind++) {
            dp[ind][0] = 1;
        }
        for (int K = 1; K <= k; K++) {
            vector<long long> suffix(n + 1, 0);
            for (int ind = n - 1; ind >= 0; ind--) {
                suffix[ind] = (dp[ind][K - 1] + suffix[ind + 1]) % m;
            }
            for (int ind = n - 1; ind >= 0; ind--) {
                long long skip = 0;
                long long take = 0;
                if (ind + 1 < n)
                    skip = dp[ind + 1][K];
                take = suffix[ind + 1];
                dp[ind][K] = (skip + take) % m;
            }
        }
        return dp[0][k];
    }
};