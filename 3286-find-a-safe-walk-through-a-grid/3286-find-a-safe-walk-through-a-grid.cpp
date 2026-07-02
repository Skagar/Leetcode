class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> vis(
            m, vector<vector<int>>(n, vector<int>(health+1, -1)));
        queue<pair<pair<int, int>, int>> q;
        if (grid[0][0] == 1)
            health = health - 1;
        if (health <= 0)
            return false;
        q.push({{0, 0}, health});
        vis[0][0][health] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int h = q.front().second;
            q.pop();
            if (r == m - 1 && c == n - 1 && h > 0)
                return true;
            for (int i = 0; i < 4; i++) {
                int delr = r + delrow[i];
                int delc = c + delcol[i];
                if (delr >= 0 && delc >= 0 && delr < m && delc < n &&
                    (h - grid[delr][delc] > 0) &&
                    vis[delr][delc][h - grid[delr][delc]] == -1) {
                    vis[delr][delc][h - grid[delr][delc]] = 1;
                    q.push({{delr, delc}, h - grid[delr][delc]});
                }
            }
        }
        return false;
    }
};