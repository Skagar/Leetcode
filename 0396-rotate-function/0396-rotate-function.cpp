class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long fzero = 0;
        long long ans = LLONG_MIN;
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            fzero += (nums[i] * i);
            sum += nums[i];
        }
        long long prev = fzero;
        if (prev > ans)
            ans = prev;
        for (long long i = 1; i <= n - 1; i++) {
            long long val =
                prev - ((n - 1) * nums[n - i]) + (sum) - (nums[n - i]);
            if (val > ans)
                ans = val;
            prev = val;
        }
        return ans;
    }
};