class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n = nums.size();
        long long cnt = 0;
        long long l = 0, r = 0;
        while (l <= r && r < n) {
            if (l == r && nums[r] != 0) {
                l++;
                r++;
            } else if (l <= r && nums[r] == 0) {
                r++;
            } else if (l < r && nums[r] != 0) {
                long long zcnt = r - l;
                cnt += (zcnt * (zcnt + 1)) / 2;
                while (l < r) {
                    l++;
                }
            }
        }
        if (l < r) {
            long long zcnt = r - l;
            cnt += (zcnt * (zcnt + 1)) / 2;
        }
        return cnt;
    }
};