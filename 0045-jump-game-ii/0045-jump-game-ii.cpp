class Solution {
    int calminjumps(int ind, int& n, vector<int>& nums, vector<int>& dp) {
        if (ind == n - 1)
            return 0;
        if (ind >= n)
            return 1e9;
        if (dp[ind] != -1)
            return dp[ind];
        int val = nums[ind];
        int ans = 1e9;
        for (int i = 1; i <= val; i++) {
            ans = min(ans, 1 + calminjumps(ind + i, n, nums, dp));
        }
        return dp[ind] = ans;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int> dp(n, -1);
        return calminjumps(0, n, nums, dp);
    }
};