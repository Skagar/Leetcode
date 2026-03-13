class Solution {
    // Memoization
    /*int countpaths(int r, int c, int& m, int& n, vector<vector<int>>& dp) {
        if (r == m - 1 && c == n - 1)
            return 1;
        if (r < 0 || c < 0 || r >= m || c >= n)
            return 0;
        if (dp[r][c] != -1)
            return dp[r][c];
        int right = countpaths(r, c + 1, m, n, dp);
        int down = countpaths(r + 1, c, m, n, dp);
        dp[r][c] = right + down;
        return dp[r][c];
    }*/

public:
    int uniquePaths(int m, int n) {
        /* 1.Memoization
         if (m == 1 || n == 1)
             return 1;
         vector<vector<int>> dp(m, vector<int>(n, -1));
         int r = 0;
         int c = 0;
         countpaths(r, c, m, n, dp);
         return dp[0][0];*/
        vector<vector<int>> dp(m, vector<int>(n, 0));
        if (m == 1 || n == 1)
            return 1;
        dp[m - 1][n - 1] = 1;
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (r == m - 1 && c == n - 1)
                    continue;
                int right = 0;
                int down = 0;
                if (c + 1 < n)
                    right = dp[r][c + 1];
                if (r + 1 < m)
                    down = dp[r + 1][c];
                dp[r][c] = right + down;
            }
        }
        return dp[0][0];
    }
};