class Solution {
private:
   
   //Memoization

   /* bool check(int ind, int& n, int tg, vector<int>& nums,
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
*/
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int tg = sum / 2;
        vector<vector<int>> dp(n, vector<int>(tg + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }
        if (nums[0] <= tg)
            dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int t = 1; t <= tg; t++) {
                bool nt = dp[i-1][t];
                bool tk = false;
                if (nums[i] <= t) {
                    tk = dp[i - 1][t - nums[i]];
                }
                dp[i][t] = tk | nt;
            }
        }
        return dp[n - 1][tg];
    }
};