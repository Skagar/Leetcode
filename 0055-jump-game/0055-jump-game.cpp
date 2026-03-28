class Solution {
    bool checkpossible(int idx, int& n, vector<int>& nums, vector<int>& dp) {
        if (idx >= n)
            return false;
        if (idx == n - 1)
            return true;
        if (dp[idx] != -1)
            return dp[idx];
        for (int i = 1; i <= nums[idx]; i++) {
            if (checkpossible(idx + i, n, nums, dp)) {
                return dp[idx] = 1;
            }
        }
        return dp[idx] = 0;
    }

public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0)
            return false;
        int n = nums.size();
        int idx = 0;
        vector<int> dp(n + 1, -1);
        return checkpossible(idx, n, nums, dp);
    }
};