class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(matrix[i][j]);
            }
        }
        for (auto& i : mp) {
            vector<int> temp = i.second;
            int ele = temp[0];
            for (int j = 0; j < temp.size(); j++) {
                if (temp[j] != ele)
                    return false;
            }
        }
        return true;
    }
};