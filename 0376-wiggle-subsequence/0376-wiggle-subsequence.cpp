class Solution {
private:
    int callength(int ind, int& n, int sign, vector<int>& nums,
                  vector<vector<int>>& dp) {
        if (ind >= n)
            return 0;
        if (dp[ind][sign + 1] != -1)
            return dp[ind][sign + 1];
        int tk = 0;
        int ntk = 0;
        if (sign == 0) {
            if (ind + 1 < n) {
                int s = nums[ind + 1] - nums[ind];
                if (s > 0)
                    tk = 1 + callength(ind + 1, n, 1, nums, dp);
                else if (s < 0)
                    tk = 1 + callength(ind + 1, n, -1, nums, dp);
                else
                    ntk = callength(ind + 1, n, 0, nums, dp);
            } else
                return 1;
        } else if (sign == 1) {
            if (ind + 1 < n) {
                int s = nums[ind + 1] - nums[ind];
                if (s < 0)
                    tk = 1 + callength(ind + 1, n, -1, nums, dp);
                else
                    ntk = callength(ind + 1, n, sign, nums, dp);
            } else
                return 1;
        } else if (sign == -1) {
            if (ind + 1 < n) {
                int s = nums[ind + 1] - nums[ind];
                if (s > 0)
                    tk = 1 + callength(ind + 1, n, 1, nums, dp);
                else
                    ntk = callength(ind + 1, n, sign, nums, dp);
            } else
                return 1;
        }
        return dp[ind][sign + 1] = tk + ntk;
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return callength(0, n, 0, nums, dp);
    }
};