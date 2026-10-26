class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        long long div = 1LL * k;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        queue<vector<int>> q;
        vector<vector<int>> vis(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && vis[i][j] == -1) {
                    long long sum = 0;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        vector<int> temp = q.front();
                        int row = temp[0];
                        int col = temp[1];
                        sum += (1LL * grid[row][col]);
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = row + delrow[k];
                            int c = col + delcol[k];
                            if (r >= 0 && c >= 0 && r < m && c < n &&
                                vis[r][c] == -1 && grid[r][c] != 0) {
                                q.push({r, c});
                                vis[r][c] = 1;
                            }
                        }
                        if (q.empty() && sum % div == 0) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};