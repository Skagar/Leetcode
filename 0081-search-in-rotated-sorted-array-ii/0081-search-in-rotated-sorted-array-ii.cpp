class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;

            if (nums[m] == target)
                return true;
            if (nums[s] == nums[m] && nums[m] == nums[e]) {
                s++;
                e--;
                continue;
            } else if (nums[m] >= nums[s]) {
                if (target >= nums[s] && target <= nums[m])
                    e = m - 1;
                else
                    s = m + 1;
            } else {
                if (target >= nums[m] && target <= nums[e])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return false;
    }
};