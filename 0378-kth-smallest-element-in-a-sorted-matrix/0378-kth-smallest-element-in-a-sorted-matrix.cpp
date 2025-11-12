class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int r = matrix.size();
        int c = matrix[0].size();
        priority_queue<int> pq;
        int rcnt = 0;
        int ccnt = 0;
        for (int i = 0; i < r; i++) {
            rcnt++;
            for (int j = 0; j < c; j++) {
                ccnt++;
                k--;
                pq.push(matrix[i][j]);
                if (k <= 0)
                    break;
            }
            if (k <= 0)
                break;
        }
        if ((ccnt % c) != 0) {
            int col = ccnt % c;
            while (col < c) {
                if (rcnt-1 < r) {
                    if (matrix[rcnt - 1][col] < pq.top()) {
                        pq.pop();
                        pq.push(matrix[rcnt - 1][col]);
                    }
                }
                col++;
            }
        }
        for (int i = rcnt; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] < pq.top()) {
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        if (!pq.empty())
            return pq.top();
        return -1;
    }
};