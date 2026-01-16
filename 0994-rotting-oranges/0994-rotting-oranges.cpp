class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        map<pair<int, int>, bool> visit;
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visit[{i, j}] = true;
                }
            }
        }
        int cnt = -1;
        while (!q.empty()) {
            int size = q.size();
            cnt++;
            for (int i = 0; i < size; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                if ((col + 1) < c && grid[row][col + 1] == 1 && // right
                    !visit[{row, col + 1}]) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                    visit[{row, col + 1}] = true;
                }
                if ((row + 1) < r && grid[row + 1][col] == 1 && // down
                    !visit[{row + 1, col}]) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                    visit[{row + 1, col}] = true;
                }
                if ((col - 1) >= 0 && grid[row][col - 1] == 1 && // left
                    !visit[{row, col - 1}]) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                    visit[{row, col - 1}] = true;
                }
                if ((row - 1) >= 0 && grid[row - 1][col] == 1 && // up
                    !visit[{row - 1, col}]) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                    visit[{row - 1, col}] = true;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        if (cnt == -1)
            return 0;
        return cnt;
    }
};