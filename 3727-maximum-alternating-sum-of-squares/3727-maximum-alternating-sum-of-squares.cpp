class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0LL;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                nums[i] = abs(nums[i]);
            }
        }
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = n - 1;
        while (i < j) {
            long long val = 1LL * nums[j];
            long long ele = 1LL * nums[i];
            ans += (1LL * val * val);
            ans -= (1LL * ele * ele);
            j--;
            i++;
        }
        if (i == j) {
            ans += (1LL * nums[i] * nums[i]);
        }
        return ans;
    }
};