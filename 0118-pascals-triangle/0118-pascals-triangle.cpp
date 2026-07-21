class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> prev;
        vector<int> curr;
        prev.push_back(1);
        ans.push_back(prev);
        for (int i = 1; i < numRows; i++) {
            curr.push_back(1);
            for (int j = 1; j < prev.size(); j++) {
                curr.push_back(prev[j] + prev[j - 1]);
            }
            curr.push_back(1);
            ans.push_back(curr);
            prev = curr;
            curr.clear();
        }
        return ans;
    }
};