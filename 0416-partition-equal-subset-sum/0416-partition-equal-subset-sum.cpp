class Solution {
private:
    bool check(int ind, int& n, int tg, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (tg == 0)
            return true;
        if (ind == 0)
            return nums[0] == tg;
        if (dp[ind][tg] != -1)
            return dp[ind][tg];
        bool ntk = check(ind - 1, n, tg, nums, dp);
        bool tk = false;
        if (nums[ind] <= tg)
            tk = check(ind - 1, n, tg - nums[ind], nums, dp);
        return dp[ind][tg] = tk || ntk;
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>>dp(n, vector<int>(sum + 1, -1));
        if (sum % 2 != 0)
            return false;
        int tg = sum / 2;
        return check(n - 1, n, tg, nums, dp);
    }
};