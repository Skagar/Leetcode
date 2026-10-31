class Solution {
private:
    int mod = 1e9 + 7;
    int dfs(int r, int c, int& m, int& n, vector<int>& delrow,
            vector<int>& delcol, vector<vector<int>>& dp,
            vector<vector<int>>& grid) {
        if (r == m - 1 && c == n - 1)
            return 1;
        if (dp[r][c] != -1)
            return (dp[r][c]) % mod;
        int zero = 0;
        int one = 0;
        for (int i = 0; i < 2; i++) {
            int delr = r + delrow[i];
            int delc = c + delcol[i];
            if (delr >= 0 && delc >= 0 && delr < m && delc < n) {
                if (grid[delr][delc] == 0) {
                    zero +=
                        (dfs(delr, delc, m, n, delrow, delcol, dp, grid) % mod);
                } else {
                    int cnt = i;
                    while (delr < m && delc < n && grid[delr][delc] != 0) {
                        if (cnt == 0) {
                            delr = delr + 1;
                            cnt = 1;
                        } else {
                            delc = delc + 1;
                            cnt = 0;
                        }
                    }
                    if (delr < m && delc < n)
                        one +=
                            (dfs(delr, delc, m, n, delrow, delcol, dp, grid) %
                             mod);
                }
            }
        }
        dp[r][c] = ((zero % mod) + (one % mod)) % mod;
        return dp[r][c];
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> delrow = {0, 1};
        vector<int> delcol = {1, 0};
        dfs(0, 0, m, n, delrow, delcol, dp, grid);
        return dp[0][0];
    }
};