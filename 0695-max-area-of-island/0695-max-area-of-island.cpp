class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int ans = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    int cnt = 0;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        cnt++;
                        for (int j = 0; j < 4; j++) {
                            int row = r + delrow[j];
                            int col = c + delcol[j];
                            if (row >= 0 && col >= 0 && row < m && col < n &&
                                grid[row][col] == 1 && vis[row][col] == 0) {
                                q.push({row, col});
                                vis[row][col] = 1;
                            }
                        }
                    }
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};