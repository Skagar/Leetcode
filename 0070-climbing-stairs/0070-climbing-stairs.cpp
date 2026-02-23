class Solution {
private:
    int calsteps(int n, vector<int>& dp) {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = calsteps(n - 1, dp) + calsteps(n - 2, dp);
        return dp[n];
    }

public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        int total = calsteps(n, dp);
        return total;
    }
};