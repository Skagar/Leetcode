class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        int delrow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int delcol[] = {0, 1, 1, 1, 0, -1, -1, -1};
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, 1});
        visit[0][0] = 1;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            if (r == m - 1 && c == n - 1)
                return t;
            for (int i = 0; i < 8; i++) {
                int row = r + delrow[i];
                int col = c + delcol[i];
                if (row >= 0 && col >= 0 && row < m && col < n &&
                    visit[row][col] == 0 && grid[row][col] == 0) {
                    q.push({{row, col}, t + 1});
                    visit[row][col] = 1;
                }
            }
        }
        return -1;
    }
};