class Solution {
private:
    void findcombinations(vector<int>& candidates, vector<vector<int>>& ans,
                          vector<int>& temp, int target, int ind, int n) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < n; i++) {
            if ((i != ind) && (candidates[i] == candidates[i - 1]))
                continue;
            if (candidates[i] > target)
                break;
            temp.push_back(candidates[i]);
            findcombinations(candidates, ans, temp, target-candidates[i], i + 1, n);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findcombinations(candidates, ans, temp, target, 0, n);
        return ans;
    }
};