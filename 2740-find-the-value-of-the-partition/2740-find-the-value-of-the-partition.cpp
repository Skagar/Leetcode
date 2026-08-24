class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = LLONG_MAX;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            long long diff = nums[i] - nums[i - 1];
            ans = min(ans, diff);
        }
        return ans;
    }
};