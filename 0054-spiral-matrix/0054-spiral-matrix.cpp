class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
       /* vector<vector<int>> vis(m, vector<int>(n, -1));
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
        return ans;*/

        int cnt=0;
        int total=m*n;
        int sr=0,sc=0,er=m-1,ec=n-1;
        vector<int> ans;
        while(cnt<total)
        {
            for(int j=sc;j<=ec && cnt<total;j++)
            {
                ans.push_back(matrix[sr][j]);
                cnt++;
            }
            sr++;
            for(int i=sr;i<=er && cnt<total;i++)
            {
                ans.push_back(matrix[i][ec]);
                cnt++;
            }
            ec--;
            for(int j=ec;j>=sc && cnt<total;j--)
            {
                ans.push_back(matrix[er][j]);
                cnt++;
            }
            er--;
            for(int i=er;i>=sr && cnt<total;i--)
            {
                ans.push_back(matrix[i][sc]);
                cnt++;
            }
            sc++;
        }
        return ans;
    }
};