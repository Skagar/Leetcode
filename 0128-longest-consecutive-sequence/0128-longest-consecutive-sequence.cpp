class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        return 0;
        sort(nums.begin(), nums.end());
        int maxlen = INT_MIN;
        int cnt = 1;
        int prev = nums[0];
        for (int i = 0; i < n; i++) {
            if (nums[i] - prev == 1) {
                cnt++;
                prev = nums[i];
            } else if (nums[i] != prev && nums[i] - prev > 1) {
                cnt = 1;
                prev = nums[i];
            }
            maxlen = max(maxlen, cnt);
        }
        return maxlen;
    }
};