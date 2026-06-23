class Solution {
private:
    int callength(int ind, int& n, int sign, vector<int>& nums) {
        if (ind >= n)
            return 0;
        int tk = 0;
        int ntk = 0;
        if (sign == 0) {
            if (ind + 1 < n) {
                int s = nums[ind + 1] - nums[ind];
                if (s > 0)
                    tk = 1 + callength(ind + 1, n, 1, nums);
                else if (s < 0)
                    tk = 1 + callength(ind + 1, n, -1, nums);
                else
                    ntk = callength(ind + 1, n, 0, nums);
            } else
                return 1;
        } else if (sign == 1) {
            if (ind + 1 < n) {
                int s = nums[ind + 1] - nums[ind];
                if (s < 0)
                    tk = 1 + callength(ind + 1, n, -1, nums);
                else
                    ntk = callength(ind + 1, n, sign, nums);
            } else
                return 1;
        } else if (sign == -1) {
            if (ind + 1 < n) {
                int s = nums[ind + 1] - nums[ind];
                if (s > 0)
                    tk = 1 + callength(ind + 1, n, 1, nums);
                else
                    ntk = callength(ind + 1, n, sign, nums);
            } else
                return 1;
        }
        return tk + ntk;
    }

public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        return callength(0, n, 0, nums);
    }
};