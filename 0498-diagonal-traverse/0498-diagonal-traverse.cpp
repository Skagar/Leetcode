class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        map<int, vector<int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        for (auto i : mp) {
            int key = i.first;
            vector<int> temp = i.second;
            int s = temp.size();
            if (key % 2 != 0) {
                for (int i = 0; i < s; i++) {
                    ans.push_back(temp[i]);
                }
            } else {
                for (int i = s - 1; i >= 0; i--) {
                    ans.push_back(temp[i]);
                }
            }
        }
        return ans;
    }
};