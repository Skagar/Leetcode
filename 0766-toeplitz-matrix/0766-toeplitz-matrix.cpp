class Solution {
private:
    bool dfs(int i, int j, int& ele, vector<vector<int>>& vis,
             vector<vector<int>>& matrix) {
        vis[i][j] = 1;
        if (((i + 1) >= 0) && ((j + 1) >= 0) && ((i + 1) < matrix.size()) &&
            ((j + 1) < matrix[0].size()) && (vis[i + 1][j + 1] == 0)) {
            i = i + 1;
            j = j + 1;
            bool check = dfs(i, j, ele, vis, matrix);
            if (check == false)
                return false;
        }
        if (matrix[i][j] != ele)
            return false;
        else
            return true;
    }

public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    int ele = matrix[i][j];
                    bool ans = dfs(i, j, ele, vis, matrix);
                    if (ans == false)
                        return false;
                }
            }
        }
        return true;
    }
};