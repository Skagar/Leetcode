class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    for (int col = 0; col < n; col++) {
                        if (col != j && board[i][col] == ch)
                            return false;
                    }
                    for (int row = 0; row < n; row++) {
                        if (row != i && board[row][j] == ch)
                            return false;
                    }
                }
            }
        }
        for (int sr = 0; sr < 9; sr += 3) {
            for (int sc = 0; sc < 9; sc += 3) {
                map<char, int> mp;

                for (int i = sr; i < sr + 3; i++) {
                    for (int j = sc; j < sc + 3; j++) {
                        if (board[i][j] != '.') {
                            if (mp.find(board[i][j]) != mp.end())
                                return false;
                            mp[board[i][j]]++;
                        }
                    }
                }
            }
        }
        return true;
    }
};