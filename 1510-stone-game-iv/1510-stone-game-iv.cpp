class Solution {
    bool checkwin(long long chance, long long n,
                  vector<vector<long long>>& dp) {
        if (n <= 0 && chance == 0)
            return false;
        if (n <= 0 && chance == 1)
            return true;
        if (dp[n][chance] != -1)
            return dp[n][chance];
        if (chance == 0) {
            bool alice = false;
            for (long long i = 1; i * i <= n; i++) {
                long long sq = i * i * 1LL;
                if (sq <= n) {
                    alice = alice | checkwin(1, n - sq, dp);
                }
            }
            return dp[n][chance] = alice;
        } else {
            bool bob = true;
            for (long long i = 1; i * i <= n; i++) {
                long long sq = i * i * 1LL;
                if (sq <= n) {
                    bob = bob & checkwin(0, n - sq, dp);
                }
            }
            return dp[n][chance] = bob;
        }
    }

public:
    bool winnerSquareGame(int n) {
        vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
        return checkwin(0, n, dp);
    }
};