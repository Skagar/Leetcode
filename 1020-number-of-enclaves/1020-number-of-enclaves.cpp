class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int totallands = 0;
        int visitedlands = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    totallands++;
                    if ((i == 0 && j >= 0) || (i == m - 1 && j >= 0) ||
                        (j == 0 && i >= 0) || (j == n - 1 && i >= 0)) {
                        visitedlands++;
                        q.push({i, j});
                        visit[i][j] = 1;
                    }
                }
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int row = r + delrow[i];
                int col = c + delcol[i];
                if (row >= 0 && col >= 0 && row < m && col < n &&
                    grid[row][col] == 1 && visit[row][col] == 0) {
                    q.push({row, col});
                    visit[row][col] = 1;
                    visitedlands++;
                }
            }
        }
        return (totallands - visitedlands);
    }
};