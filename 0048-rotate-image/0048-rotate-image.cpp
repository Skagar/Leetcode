class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int colcnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = colcnt; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            colcnt++;
        }
        int lcol = 0;
        int rcol = n - 1;
        while (lcol <= rcol) {
            for (int i = 0; i < n; i++) {
                swap(matrix[i][lcol], matrix[i][rcol]);
            }
            lcol++;
            rcol--;
        }
    }
};