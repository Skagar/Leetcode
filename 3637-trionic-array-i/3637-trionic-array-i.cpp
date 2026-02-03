class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        int p = 0;
        int q = 0;
        for (int i = 1; i < n; i++) {
            if ((nums[i] - nums[i - 1]) > 0)
                continue;
            else {
                p = i - 1;
                break;
            }
        }
        for (int i = p + 1; i < n; i++) {
            if ((nums[i] - nums[i - 1]) < 0)
                continue;
            else {
                q = i - 1;
                break;
            }
        }
        for (int i = q + 1; i < n; i++) {
            if ((nums[i] - nums[i - 1]) > 0)
                continue;
            else {
                return false;
            }
        }
        if (p != 0 && q != 0 && p < q)
            return true;
        return false;
    }
};