class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (sum <= 0)
                sum = 0;
            sum += nums[i];
            ans = max(ans, sum);
        }
        return (int)ans;
    }
};