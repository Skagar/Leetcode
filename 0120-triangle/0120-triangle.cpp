class Solution {
private:
    // 1. Memoization
    /* int countminpath(int r, int c, int m, vector<vector<int>>& dp,
                      vector<vector<int>>& triangle) {
         if (r == m - 1)
             return triangle[r][c];
         if (dp[r][c] != -1)
             return dp[r][c];
         int right =
             triangle[r][c] + countminpath(r + 1, c + 1, m, dp, triangle);
         int down = triangle[r][c] + countminpath(r + 1, c, m, dp, triangle);
         dp[r][c] = min(right, down);
         return dp[r][c];
     }
 */
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if (m == 1)
            return triangle[0][0];
        vector<vector<int>> dp;
        for (int i = 0; i < m; i++)
            dp.push_back(vector<int>(triangle[i].size(), -1));
        for (int r = m - 1; r >= 0; r--) {
            for (int c = triangle[r].size() - 1; c >= 0; c--) {
                if (r == m - 1) {
                    dp[r][c] = triangle[r][c];
                    continue;
                }
                int right = triangle[r][c] + dp[r + 1][c + 1];
                int down = triangle[r][c] + dp[r + 1][c];
                dp[r][c] = min(right, down);
            }
        }
        return dp[0][0];
    }
};