class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].length();
        vector<vector<char>> mat(m, vector<char>(n));
        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(65, -1)));
        queue<vector<int>> q;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        int targetMask = 0;
        int keyCnt = 0;
        for (int i = 0; i < m; i++) {
            string s = grid[i];
            for (int j = 0; j < n; j++) {
                mat[i][j] = s[j];
                if (s[j] == 'a' || s[j] == 'b' || s[j] == 'c' || s[j] == 'd' ||
                    s[j] == 'e' || s[j] == 'f')
                    keyCnt++;
                if (s[j] == '@') {
                    q.push({i, j, 0, 0});
                    vis[i][j][0] = 1;
                }
                if (s[j] >= 'a' && s[j] <= 'f')
                    targetMask |= (1 << (s[j] - 'a'));
            }
        }
        while (!q.empty()) {
            vector<int> temp = q.front();
            int r = temp[0];
            int c = temp[1];
            int steps = temp[2];
            int mask = temp[3];
            q.pop();
            if (mask == targetMask)
                return steps;
            for (int i = 0; i < 4; i++) {
                int delr = r + delrow[i];
                int delc = c + delcol[i];
                if (delr >= 0 && delc >= 0 && delr < m && delc < n &&
                    mat[delr][delc] != '#') {
                    char ch = mat[delr][delc];
                    if ((ch == '.' || ch == '@') &&
                        vis[delr][delc][mask] == -1) {
                        q.push({delr, delc, steps + 1, mask});
                        vis[delr][delc][mask] = 1;

                    } else if ((ch == 'a' || ch == 'b' || ch == 'c' ||
                                ch == 'd' || ch == 'e' || ch == 'f') &&
                               vis[delr][delc][mask | 1 << (ch - 'a')] == -1) {
                        q.push({delr, delc, steps + 1, mask | 1 << (ch - 'a')});
                        vis[delr][delc][mask | 1 << (ch - 'a')] = 1;

                    } else if (ch >= 'A' && ch <= 'F') {
                        if ((mask & (1 << (ch - 'A'))) &&
                            vis[delr][delc][mask] == -1) {
                            q.push({delr, delc, steps + 1, mask});
                            vis[delr][delc][mask] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};