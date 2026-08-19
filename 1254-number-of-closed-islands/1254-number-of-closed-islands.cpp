class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i != 0 && i != m - 1 && j != 0 && j != n - 1 &&
                    grid[i][j] == 0 && vis[i][j] == -1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    bool flag = true;
                    while (!q.empty()) {
                        int s = q.size();
                        for (int k = 0; k < s; k++) {
                            int r = q.front().first;
                            int c = q.front().second;
                            q.pop();
                            for (int l = 0; l < 4; l++) {
                                int delr = r + delrow[l];
                                int delc = c + delcol[l];
                                if (delr >= 0 && delc >= 0 && delr < m &&
                                    delc < n && grid[delr][delc] == 0 &&
                                    vis[delr][delc] == -1) {
                                    vis[delr][delc] = 1;
                                    q.push({delr, delc});
                                    if (delc == 0 || delr == 0 ||
                                        delr == m - 1 || delc == n - 1)
                                        flag = false;
                                }
                            }
                        }
                    }
                    if (flag == true)
                        ans++;
                }
            }
        }
        return ans;
    }
};