class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int cnt1 = 0, cnt2 = 0;
        while (r < n) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            cnt1 += (r - l + 1);
            r++;
        }
        r = 0;
        l = 0;
        sum = 0;
        while (r < n) {
            sum += nums[r];
            while (l <= r && sum >= goal) {
                sum -= nums[l];
                l++;
            }
            cnt2 += (r - l + 1);
            r++;
        }
        return cnt1 - cnt2;
    }
};