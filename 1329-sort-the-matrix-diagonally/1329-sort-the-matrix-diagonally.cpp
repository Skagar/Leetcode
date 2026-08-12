class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[(i - j)].push_back(mat[i][j]);
            }
        }
        for (auto i : mp) {
            int diff = i.first;
            vector<int> temp = i.second;
            sort(temp.begin(), temp.end());
            int ind = 0;
            cout << diff << "->";
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if ((i - j) == diff) {
                        cout << temp[ind] << " ";
                        ans[i][j] = temp[ind++];
                    }
                }
            }
            cout << endl;
        }
        return ans;
    }
};