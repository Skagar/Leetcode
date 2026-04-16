class Solution {
    bool checkword(int r, int c, int ind, int& m, int& n, int& len,
                   string& word, vector<vector<char>>& board,
                   vector<vector<int>>& vis) {
        if (ind >= len)
            return false;
        if (r >= m || c >= n || r < 0 || c < 0)
            return false;
        if (ind == len - 1 && board[r][c] == word[ind])
            return true;
        bool right = false, left = false, up = false, down = false;
        if (board[r][c] == word[ind]) {
            vis[r][c] = 1;
            if (c + 1 < n && vis[r][c + 1] == 0) {
                right =
                    checkword(r, c + 1, ind + 1, m, n, len, word, board, vis);
            }
            if (c - 1 >= 0 && vis[r][c - 1] == 0) {
                left =
                    checkword(r, c - 1, ind + 1, m, n, len, word, board, vis);
            }
            if (r + 1 < m && vis[r + 1][c] == 0) {
                down =
                    checkword(r + 1, c, ind + 1, m, n, len, word, board, vis);
            }
            if (r - 1 >= 0 && vis[r - 1][c] == 0) {
                up = checkword(r - 1, c, ind + 1, m, n, len, word, board, vis);
            }
        }
        vis[r][c] = 0;
        return right || left || down || up;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> stpt;
        char ch = word[0];
        int m = board.size();
        int n = board[0].size();
        int len = word.length();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == ch)
                    stpt.push_back({i, j});
            }
        }
        for (int i = 0; i < stpt.size(); i++) {
            int r = stpt[i].first;
            int c = stpt[i].second;
            vector<vector<int>> vis(m, vector<int>(n, 0));
            vis[r][c] = 1;
            if (checkword(r, c, 0, m, n, len, word, board, vis))
                return true;
        }
        return false;
    }
};