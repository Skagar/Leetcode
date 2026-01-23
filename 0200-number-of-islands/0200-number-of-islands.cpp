class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        int count = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int ele = grid[i][j] - '0';
                if (ele == 1 && visit[i][j] == false) {
                    count++;
                    q.push({i, j});
                    visit[i][j] = true;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int row = r + delrow[i];
                            int col = c + delcol[i];
                            if (row >= 0 && col >= 0 && row < m && col < n &&
                                grid[row][col] == '1' && !visit[row][col]) {
                                q.push({row, col});
                                visit[row][col] = true;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};