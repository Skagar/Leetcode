class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> v;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    v.push_back({i, j});
                }
            }
        }

        for (int i = 0; i < v.size(); i++) {
            int r = v[i].first;
            int c = v[i].second;
            for (int j = 0; j < n; j++) {
                matrix[r][j] = 0;
            }
            for (int j = 0; j < m; j++) {
                matrix[j][c] = 0;
            }
        }
    }
};