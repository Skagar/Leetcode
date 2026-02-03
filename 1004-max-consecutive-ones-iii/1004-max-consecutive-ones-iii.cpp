class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        long long maxlen = 0;
        int cnt = 0;
        long long len = 0;
        while (r < n) {
            if (cnt <= k) {
                if (nums[r] == 0)
                    cnt++;
                len = r - l;
                maxlen = max(len, maxlen);
                r++;
            } else {
                while (cnt > k) {
                    if (nums[l] == 0)
                        cnt--;
                    l++;
                }
            }
        }
        if (cnt <= k) {
            len = r - l;
            maxlen = max(len, maxlen);
        }
        return maxlen;
    }
};