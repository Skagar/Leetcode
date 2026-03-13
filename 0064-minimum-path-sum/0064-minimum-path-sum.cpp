class Solution {
    int calminpathsum(int r, int c, int& m, int& n, vector<vector<int>>& grid,
                      vector<vector<int>>& dp) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return INT_MAX;
        if (r == m - 1 && c == n - 1) {
            return grid[r][c];
        }
        if (dp[r][c] != -1)
            return dp[r][c];
        int right = calminpathsum(r, c + 1, m, n, grid, dp);
        int down = calminpathsum(r + 1, c, m, n, grid, dp);
        dp[r][c] = grid[r][c] + min(right, down);
        return dp[r][c];
    }

public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = 0;
        int c = 0;
        int m = grid.size();
        int n = grid[0].size();
        if(m==1 && n==1)
        return grid[r][c];
        vector<vector<int>> dp(m, vector<int>(n, -1));
        calminpathsum(r, c, m, n, grid, dp);
        return dp[0][0];
    }
};