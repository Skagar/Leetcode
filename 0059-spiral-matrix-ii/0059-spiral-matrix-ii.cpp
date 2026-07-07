class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n, -1));
        if(n==1)
        {
            mat[0][0]=1;
            return mat;
        }
        int r = 0;
        int c = 0;
        int cnt = 1;
        bool rf = true;
        bool rvi = false;
        bool rvd = false;
        bool cf = false;
        bool cvi = true;
        bool cvd = false;
        while (mat[r][c] == -1) {
            if (rf == true && cvi == true) {
                rf = false;
                cvi = false;
                rvi = true;
                cf = true;
                while (r < n && c < n && r >= 0 && c >= 0 && mat[r][c] == -1) {
                    mat[r][c] = cnt;
                    cnt++;
                    c++;
                }
                c--;
                r++;
            } else if (rvi == true && cf == true) {
                rvi = false;
                cf = false;
                rf = true;
                cvd = true;
                while (r < n && c < n && r >= 0 && c >= 0 && mat[r][c] == -1) {
                    mat[r][c] = cnt;
                    cnt++;
                    r++;
                }
                c--;
                r--;
            } else if (rf = true && cvd == true) {
                rf = false;
                cvd = false;
                rvd = true;
                cf = true;
                while (r < n && c < n && r >= 0 && c >= 0 && mat[r][c] == -1) {
                    mat[r][c] = cnt;
                    cnt++;
                    c--;
                }
                c++;
                r--;
            } else if (rvd = true && cf == true) {
                rvd = false;
                cf = false;
                rf = true;
                cvi = true;
                while (r < n && c < n && r >= 0 && c >= 0 && mat[r][c] == -1) {
                    mat[r][c] = cnt;
                    cnt++;
                    r--;
                }
                c++;
                r++;
            }
        }
        return mat;
    }
};