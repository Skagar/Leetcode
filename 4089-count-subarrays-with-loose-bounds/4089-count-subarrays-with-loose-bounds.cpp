class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long cnt = 0;
        while (r < n) {
            if (nums[r] < minK || nums[r] > maxK) {
                long long ele = 1LL * (r - l);
                cnt += (1LL * ele * (ele + 1)) / 2;
                r++;
                l = r;
                continue;
            } else if (nums[r] >= minK && nums[r] <= maxK) {
                r++;
            }
        }
        long long ele = 1LL * (r - l);
        cnt += (1LL * ele * (ele + 1)) / 2;
        return cnt;
    }
};