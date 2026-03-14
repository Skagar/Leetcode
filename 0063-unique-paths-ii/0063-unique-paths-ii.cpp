class Solution {
private:
    int countpaths(int r, int c, int& m, int& n,
                   vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return 0;
        if (r == m - 1 && c == n - 1)
            return 1;
        if (dp[r][c] != -1)
            return dp[r][c];
        int right = 0;
        int down = 0;
        if ((c + 1 < n) && (obstacleGrid[r][c + 1] == 0))
            right = countpaths(r, c + 1, m, n, obstacleGrid, dp);
        if ((r + 1 < m) && (obstacleGrid[r + 1][c] == 0))
            down = countpaths(r + 1, c, m, n, obstacleGrid, dp);
        dp[r][c] = right + down;
        return dp[r][c];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int r = 0;
        int c = 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (obstacleGrid[r][c] == 1)
            return 0;
        if (m == 1 && n == 1)
            return 1;
        countpaths(r, c, m, n, obstacleGrid, dp);
        return dp[0][0];
    }
};