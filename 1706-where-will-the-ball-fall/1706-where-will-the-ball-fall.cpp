class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n, -1);
        for (int k = 0; k < n; k++) {
            int i = 0;
            int j = k;
            while (i < m && i >= 0 && j < n && j >= 0) {
                int v = grid[i][j];
                if (v == 1) {
                    if (j == n - 1)
                        break;
                    else if (grid[i][j + 1] == -1)
                        break;
                    if (i == m - 1) {
                        j++;
                        ans[k] = j;
                        break;
                    }
                    i++;
                    j++;
                } else {
                    if (j == 0)
                        break;
                    else if (grid[i][j - 1] == 1)
                        break;
                    if (i == m - 1) {
                        j--;
                        ans[k] = j;
                        break;
                    }
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};