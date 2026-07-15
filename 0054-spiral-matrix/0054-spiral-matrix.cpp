class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));
        int r = 0, c = 0;
        bool ci = true, rc = true, cc = false, cd = false, ri = false,
             rd = false;
        vector<int> ans;
        while (r < m && c < n && r >= 0 && c >= 0 && vis[r][c] == -1) {
            if (rc == true && ci == true) {
                rc = false;
                ci = false;
                cc = true;
                ri = true;
                while (c < n && vis[r][c] == -1) {
                    ans.push_back(matrix[r][c]);
                    vis[r][c] = 1;
                    c++;
                }
                c--;
                r++;
            } else if (cc == true && ri == true) {
                cc = false;
                ri = false;
                rc = true;
                cd = true;
                while (r < m && vis[r][c]==-1) {
                    ans.push_back(matrix[r][c]);
                    vis[r][c] = 1;
                    r++;
                }
                r--;
                c--;
            } else if (rc == true && cd == true) {
                rc = false;
                cd = false;
                cc = true;
                rd = true;
                while (c >= 0 && vis[r][c] == -1) {
                    ans.push_back(matrix[r][c]);
                    vis[r][c] = 1;
                    c--;
                }
                c++;
                r--;
            } else if (cc == true && rd == true) {
                cc = false;
                rd = false;
                rc = true;
                ci = true;
                while (r >= 0 && vis[r][c] == -1) {
                    ans.push_back(matrix[r][c]);
                    vis[r][c] = 1;
                    r--;
                }
                r++;
                c++;
            }
        }
        return ans;
    }
};