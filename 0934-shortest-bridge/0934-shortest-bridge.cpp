class Solution {
private:
    /*int calmin(int i, int j, int& n, vector<vector<int>>& dfsvis,
               vector<vector<int>>& grid, vector<int>& delrow,
               vector<int>& delcol) {
        int ans = 1e9;
        for (int k = 0; k < 4; k++) {
            int r = i + delrow[k];
            int c = j + delcol[k];
            if (r >= 0 && c >= 0 && c < n && r < n && dfsvis[r][c] == -1) {
                if (grid[r][c] == 0) {
                    dfsvis[r][c] = 1;
                    ans = min(
                        ans, 1 + calmin(r, c, n, dfsvis, grid, delrow, delcol));
                    dfsvis[r][c] = -1;
                } else if (grid[r][c] == 2)
                    return 0;
            }
        }
        return ans;
    }*/

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, -1));
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == -1) {
                    cnt++;
                    queue<pair<pair<int, int>, int>> q;
                    q.push({{i, j}, cnt});
                    vis[i][j] = 1;
                    grid[i][j] = cnt;
                    while (!q.empty()) {
                        int r = q.front().first.first;
                        int c = q.front().first.second;
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int delr = r + delrow[k];
                            int delc = c + delcol[k];
                            if (delr >= 0 && delc >= 0 && delr < n &&
                                delc < n && grid[delr][delc] == 1 &&
                                vis[delr][delc] == -1) {
                                q.push({{delr, delc}, cnt});
                                vis[delr][delc] = 1;
                                grid[delr][delc] = cnt;
                            }
                        }
                    }
                }
            }
        }
        vector<vector<int>> bfsvis(n, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && bfsvis[i][j] == -1) {
                    bfsvis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int delr = r + delrow[k];
                int delc = c + delcol[k];
                if (delr >= 0 && delc >= 0 && delr < n && delc < n &&
                    bfsvis[delr][delc] == -1) {
                    if (grid[delr][delc] == 0) {
                        q.push({{delr, delc}, steps + 1});
                        bfsvis[delr][delc] = 1;
                    } else if (grid[delr][delc] == 2)
                        return steps;
                }
            }
        }
        return -1;
    }
};