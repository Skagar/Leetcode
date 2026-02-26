class Solution {
private:
    void gencombinations(int ind, int& k, vector<int>& arr, vector<int>& temp,
                         vector<vector<int>>& ans) {
        if (ind >= arr.size()) {
            if (temp.size() == k)
                ans.push_back(temp);
            return;
        }
        gencombinations(ind + 1, k, arr, temp, ans);
        temp.push_back(arr[ind]);
        gencombinations(ind + 1, k, arr, temp, ans);
        temp.pop_back();
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            arr[i] = i;
        }
        vector<int> temp;
        vector<vector<int>> ans;
        int ind = 1;
        gencombinations(ind, k, arr, temp, ans);
        return ans;
    }
};