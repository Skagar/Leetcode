class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (m == 0 && nums[m] != nums[m + 1])
                return nums[m];
            else if (m == n - 1 && nums[m] != nums[m - 1])
                return nums[m];
            else if (nums[m] != nums[m - 1] && nums[m] != nums[m + 1])
                return nums[m];
            else if (nums[m] == nums[m + 1]) {
                if (m % 2 == 0)
                    s = m + 1;
                else
                    e = m - 1;
            } else if (nums[m] == nums[m - 1]) {
                if ((m - 1) % 2 == 0)
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return -1;
    }
};