class Solution {
    bool dfs(int i, int j, int pi, int pj, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int m, int n) {
        
        vis[i][j] = 1;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || nj < 0 || ni >= m || nj >= n) continue;
            if (grid[ni][nj] != grid[i][j]) continue;

            if (!vis[ni][nj]) {
                if (dfs(ni, nj, i, j, grid, vis, m, n))
                    return true;
            } 
            else if (ni != pi || nj != pj) {
                return true; // cycle found
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, vis, m, n))
                        return true;
                }
            }
        }
        return false;
    }
};