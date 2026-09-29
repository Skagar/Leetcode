class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if (grid[0][0] == ')')
            return false;
        queue<vector<int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> vis(
            m + 1, vector<vector<int>>(n + 1, vector<int>(m + n, -1)));
        q.push({0, 0, 1});
        vis[0][0][1] = 1;
        vector<int> delrow = {0, 1};
        vector<int> delcol = {1, 0};
        while (!q.empty()) {
            vector<int> temp = q.front();
            q.pop();
            int r = temp[0];
            int c = temp[1];
            int bcnt = temp[2];
            if (r == m - 1 && c == n - 1 && bcnt == 0)
                return true;
            for (int i = 0; i < 2; i++) {
                int dr = r + delrow[i];
                int dc = c + delcol[i];
                if (dr >= 0 && dc >= 0 && dr < m && dc < n) {
                    char ch = grid[dr][dc];
                    if (ch == '(' && vis[dr][dc][bcnt + 1] == -1) {
                        q.push({dr, dc, bcnt + 1});
                        vis[dr][dc][bcnt + 1] = 1;
                    } else if (ch == ')') {
                        if (bcnt > 0 && vis[dr][dc][bcnt - 1] == -1) {
                            q.push({dr, dc, bcnt - 1});
                            vis[dr][dc][bcnt - 1] = 1;
                        }
                    }
                }
            }
        }
        return false;
    }
};