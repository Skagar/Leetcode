class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visit(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        int cnt = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X' && visit[i][j] == 0) {
                    cnt++;
                    q.push({i, j});
                    visit[i][j] = 1;
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        for (int i = 0; i < 4; i++) {
                            int row = r + delrow[i];
                            int col = c + delcol[i];
                            if (row >= 0 && col >= 0 && row < m && col < n &&
                                visit[row][col] == 0 &&
                                board[row][col] == 'X') {
                                q.push({row, col});
                                visit[row][col] = 1;
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};