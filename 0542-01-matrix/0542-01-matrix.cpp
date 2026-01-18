class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            ans[r][c] = dist;
            for (int i = 0; i < 4; i++) {
                int row = r + delrow[i];
                int col = c + delcol[i];
                if (row >= 0 && row < m && col >= 0 && col < n &&
                    vis[row][col] == 0) {
                    vis[row][col] = 1;
                    q.push({{row, col}, dist + 1});
                }
            }
        }
        return ans;
    }
};