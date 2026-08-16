class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int tg = target;
        int s = 0;
        int e = (n * m) - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            int r = mid / n;
            int c = mid % n;
            if (matrix[r][c] == tg)
                return true;
            else if (matrix[r][c] < tg)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return false;
    }
};