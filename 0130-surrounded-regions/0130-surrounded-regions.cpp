class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == 0 && j >= 0) || (i == m - 1 && j >= 0) ||
                    (j == 0 && i >= 0) || (j == n - 1 && i >= 0)) {
                    if (board[i][j] == 'O') {
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
                if (row >= 0 && row < m && col >= 0 && col < n &&
                    visit[row][col] == 0 && board[row][col] == 'O') {
                    visit[row][col] = 1;
                    q.push({row, col});
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O' && visit[i][j] == 0)
                    board[i][j] = 'X';
            }
        }
    }
};