class Solution {
    int calsum(vector<int>& nums, vector<int>& dp, int ind) {
        if (ind < 0)
            return 0;
        if (ind == 0)
            return nums[0];
        if (dp[ind] != -1)
            return dp[ind];
        int take = nums[ind] + calsum(nums, dp, ind - 2);
        int nottake = calsum(nums, dp, ind - 1);
        dp[ind] = max(take, nottake);
        return dp[ind];
    }
    int calsum2(vector<int>& nums, vector<int>& dp, int ind) {
        if (ind < 1)
            return 0;
        if (ind == 1)
            return nums[1];
        if (dp[ind] != -1)
            return dp[ind];
        int take = nums[ind] + calsum2(nums, dp, ind - 2);
        int nottake = calsum2(nums, dp, ind - 1);
        dp[ind] = max(take, nottake);
        return dp[ind];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int ind1 = n - 2;
        int ind2 = n - 1;
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int ans1 = calsum(nums, dp1, ind1);
        int ans2 = calsum2(nums, dp2, ind2);
        return max(ans1, ans2);
    }
};