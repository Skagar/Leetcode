class Solution {
    int calsum(vector<int>& nums, vector<int>& dp, int ind) {
        if (ind < 0)
            return 0;
        if (ind == 0)
            return nums[ind];
        if (dp[ind] != -1)
            return dp[ind];
        int take = nums[ind] + calsum(nums, dp, ind - 2);
        int nottake = 0 + calsum(nums, dp, ind - 1);
        dp[ind] = max(take, nottake);
        return dp[ind];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int ind = n - 1;
        vector<int> dp(n, -1);
        return calsum(nums, dp, ind);
    }
};