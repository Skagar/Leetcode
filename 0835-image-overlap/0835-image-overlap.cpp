class Solution {
    int calMaxOverlap(int r, int c, int& n, vector<vector<int>>& img1,
                      vector<vector<int>>& img2) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int newi = i + r;
                int newj = j + c;
                if (newi < 0 || newj < 0 || newi >= n || newj >= n)
                    continue;
                if (img1[i][j] == 1 && img2[newi][newj] == 1)
                    cnt++;
            }
        }
        return cnt;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans = INT_MIN;
        for (int r = -n + 1; r < n; r++) {
            for (int c = -n + 1; c < n; c++) {
                ans = max(ans, calMaxOverlap(r, c, n, img1, img2));
            }
        }
        return ans;
    }
};