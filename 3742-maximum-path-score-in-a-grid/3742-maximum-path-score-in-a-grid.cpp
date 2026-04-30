class Solution {
    int calmaxcost(int r, int c, int& m, int& n, vector<vector<int>>& grid,
                   int k, vector<vector<vector<int>>>& dp) {
        if (r < 0 || c < 0 || r >= m || c >= n)
            return -1e9;
        if (r == m - 1 && c == n - 1) {
            if (grid[r][c] == 0 && grid[r][c] <= k)
                return grid[r][c];
            else if (grid[r][c] == 1 && grid[r][c] <= k)
                return grid[r][c];
            else if (grid[r][c] == 2 && 1 <= k)
                return grid[r][c];
            else
                return -1e9;
        }
        if (dp[r][c][k] != -1)
            return dp[r][c][k];
        int right = -1e9, down = -1e9;
        int val = grid[r][c];
        if (val == 0 && val <= k)
            right = grid[r][c] + calmaxcost(r, c + 1, m, n, grid, k - 0, dp);
        else if (val == 1 && val <= k)
            right = grid[r][c] + calmaxcost(r, c + 1, m, n, grid, k - 1, dp);
        else if (val == 2 && 1 <= k)
            right = grid[r][c] + calmaxcost(r, c + 1, m, n, grid, k - 1, dp);
        if (val == 0 && val <= k)
            down = grid[r][c] + calmaxcost(r + 1, c, m, n, grid, k - 0, dp);
        else if (val == 1 && val <= k)
            down = grid[r][c] + calmaxcost(r + 1, c, m, n, grid, k - 1, dp);
        else if (val == 2 && 1 <= k)
            down = grid[r][c] + calmaxcost(r + 1, c, m, n, grid, k - 1, dp);
        return dp[r][c][k] = max(right, down);
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int cost = calmaxcost(0, 0, m, n, grid, k, dp);
        if (cost < 0)
            return -1;
        return cost;
    }
};