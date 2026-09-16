class Solution {
    bool check(vector<vector<int>>& mat, int& row, int& col) {
        queue<pair<int, int>> q;
        vector<vector<int>> vis(row, vector<int>(col, -1));
        for (int i = 0; i < col; i++) {
            if (mat[0][i] == 0) {
                q.push({0, i});
                vis[0][i] = 1;
            }
        }
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if (r == row - 1)
                return true;
            for (int i = 0; i < 4; i++) {
                int delr = r + delrow[i];
                int delc = c + delcol[i];
                if (delr >= 0 && delc >= 0 && delr < row && delc < col &&
                    mat[delr][delc] == 0 && vis[delr][delc] == -1) {
                    q.push({delr, delc});
                    vis[delr][delc] = 1;
                }
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int dcnt = 0;
        int s = 0;
        int e = cells.size() - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            vector<vector<int>> mat(row, vector<int>(col, 0));
            for (int i = 0; i <= m; i++) {
                int r = cells[i][0] - 1;
                int c = cells[i][1] - 1;
                mat[r][c] = 1;
            }
            if (check(mat, row, col)) {
                dcnt = m + 1;
                s = m + 1;
            } else
                e = m - 1;
        }
        return dcnt;
    }
};