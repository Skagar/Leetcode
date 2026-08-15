class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>> q;
        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        int steps = 0;
        q.push({0, 0, k});
        vis[0][0][k] = 1;
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                vector<int> temp = q.front();
                q.pop();
                int r = temp[0];
                int c = temp[1];
                int K = temp[2];
                if (r == m - 1 && c == n - 1)
                    return steps;
                for (int j = 0; j < 4; j++) {
                    int delr = r + delrow[j];
                    int delc = c + delcol[j];
                    if (delr >= 0 && delc >= 0 && delr < m && delc < n) {
                        if (grid[delr][delc] == 0 && vis[delr][delc][K] == -1) {
                            q.push({delr, delc, K});
                            vis[delr][delc][K] = 1;
                        } else if (grid[delr][delc] == 1 && K > 0 &&
                                   vis[delr][delc][K - 1] == -1) {
                            q.push({delr, delc, K - 1});
                            vis[delr][delc][K - 1] = 1;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};