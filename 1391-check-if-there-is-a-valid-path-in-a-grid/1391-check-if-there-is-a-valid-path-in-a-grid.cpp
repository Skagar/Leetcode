class Solution {
    bool checkpath(int r, int c, int& m, int& n, vector<vector<int>>& grid,
                   vector<vector<int>>& vis) {

        if (r == m - 1 && c == n - 1)
            return true;

        vis[r][c] = 1;

        int val = grid[r][c];
        bool ans = false;

        // LEFT
        if (c - 1 >= 0 && vis[r][c - 1] == -1) {
            int next = grid[r][c - 1];
            if ((val == 1 || val == 3 || val == 5) &&  // current allows LEFT
                (next == 1 || next == 4 || next == 6)) // neighbor allows RIGHT
                ans |= checkpath(r, c - 1, m, n, grid, vis);
        }

        // RIGHT
        if (c + 1 < n && vis[r][c + 1] == -1) {
            int next = grid[r][c + 1];
            if ((val == 1 || val == 4 || val == 6) &&  // current allows RIGHT
                (next == 1 || next == 3 || next == 5)) // neighbor allows LEFT
                ans |= checkpath(r, c + 1, m, n, grid, vis);
        }

        // UP
        if (r - 1 >= 0 && vis[r - 1][c] == -1) {
            int next = grid[r - 1][c];
            if ((val == 2 || val == 5 || val == 6) &&  // current allows UP
                (next == 2 || next == 3 || next == 4)) // neighbor allows DOWN
                ans |= checkpath(r - 1, c, m, n, grid, vis);
        }

        // DOWN
        if (r + 1 < m && vis[r + 1][c] == -1) {
            int next = grid[r + 1][c];
            if ((val == 2 || val == 3 || val == 4) &&  // current allows DOWN
                (next == 2 || next == 5 || next == 6)) // neighbor allows UP
                ans |= checkpath(r + 1, c, m, n, grid, vis);
        }

        return ans;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> vis(m, vector<int>(n, -1));

        return checkpath(0, 0, m, n, grid, vis);
    }
};