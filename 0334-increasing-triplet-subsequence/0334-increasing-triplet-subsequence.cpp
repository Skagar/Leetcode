class Solution {
    /* bool checkincreasingTriplet(int ind, int prevind, int len, int& n,
                                 vector<int>& nums,
                                 vector<vector<vector<int>>>& dp) {
         if (len == 3)
             return true;
         if (ind > n)
             return false;
         if (dp[ind][prevind][len] != -1)
             return dp[ind][prevind][len];
         bool tk = false;
         bool ntk = false;
         if (prevind == 0) {
             tk = checkincreasingTriplet(ind + 1, ind, len + 1, n, nums, dp);
             ntk = checkincreasingTriplet(ind + 1, prevind, len, n, nums, dp);
         } else {
             if (nums[ind - 1] > nums[prevind - 1]) {
                 tk = checkincreasingTriplet(ind + 1, ind, len + 1, n, nums,
     dp); ntk = checkincreasingTriplet(ind + 1, prevind, len, n, nums, dp); }
     else ntk = checkincreasingTriplet(ind + 1, prevind, len, n, nums, dp);
         }
         return dp[ind][prevind][len] = tk || ntk;
     }
 */
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        // MLE
        /*int len = 0;
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(n, vector<int>(4, -1)));
        return checkincreasingTriplet(1, 0, 0, n, nums, dp);*/
        int first = INT_MAX;
        int second = INT_MAX;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x < first)
                first = x;
            else if (x > first && x < second)
                second = x;
            else if (x > second)
                return true;
        }
        return false;
    }
};