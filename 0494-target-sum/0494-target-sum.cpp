class Solution {
    int countways(int ind, int tg, vector<int>& nums) {
        if (ind == 0) {
            if ((tg + nums[ind] == 0) && (tg - nums[ind] == 0))
                return 2;
            else if (tg + nums[ind] == 0)
                return 1;
            else if (tg - nums[ind] == 0)
                return 1;
            else
                return 0;
        }
        int plus = 0;
        int minus = 0;
        plus += countways(ind - 1, tg + nums[ind], nums);
        minus += countways(ind - 1, tg - nums[ind], nums);
        return plus + minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int tg = target;
        return countways(n - 1, tg, nums);
    }
};