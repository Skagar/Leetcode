class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n - 1;
        int ans = INT_MAX;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[s] <= nums[m]) {
                ans = min(ans, nums[s]);
                s = m + 1;
            } else {
                ans = min(ans, nums[m]);
                e = m - 1;
            }
        }
        return ans;
    }
};