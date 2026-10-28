class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minxor = INT_MAX;
        int delrow[] = {0, 1};
        int delcol[] = {1, 0};
        vector<vector<vector<bool>>> vis(
            m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        queue<array<int, 3>> q;
        q.push({0, 0, grid[0][0]});
        vis[0][0][grid[0][0]] = true;
        while (!q.empty()) {
            auto [r, c, x] = q.front();
            q.pop();
            if (r == m - 1 && c == n - 1) {
                minxor = min(minxor, x);
            }
            for (int i = 0; i < 2; i++) {
                int row = r + delrow[i];
                int col = c + delcol[i];
                if (row >= 0 && col >= 0 && row < m && col < n &&
                    !vis[row][col][x ^ grid[row][col]]) {
                    q.push({row, col, x ^ grid[row][col]});
                    vis[row][col][x ^ grid[row][col]] = true;
                }
            }
        }
        return minxor;
    }
};