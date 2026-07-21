class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 1; i <= k; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                temp.push_back(grid[j][n - 1]);
            }
            for (int j = n - 1; j > 0; j--) {
                for (int p = 0; p < m; p++) {
                    grid[p][j] = grid[p][j - 1];
                }
            }
            grid[0][0] = temp[temp.size() - 1];
            for (int j = 1; j < m; j++) {
                grid[j][0] = temp[j - 1];
            }
        }
        return grid;
    }
};