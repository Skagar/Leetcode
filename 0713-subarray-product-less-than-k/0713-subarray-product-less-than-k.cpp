class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int r = 0;
        int l = 0;
        int cnt = 0;
        __int128 p = 1;
        while (r < n) {
            p = p * nums[r];
            while (l <= r && p >= k) {
                p = p / nums[l];
                l++;
            }
            if (p < k)
                cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
};