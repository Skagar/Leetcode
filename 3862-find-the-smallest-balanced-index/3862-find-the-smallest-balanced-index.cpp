class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixsum(n);
        vector<long long> suffixprod(n);
        prefixsum[0] = 0;
        suffixprod[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            __int128 temp = (__int128)suffixprod[i + 1] * nums[i + 1];
            if (temp > LLONG_MAX)
                temp = LLONG_MAX;
            suffixprod[i] = (long long)temp;
        }
        for (int i = 0; i < n; i++) {
            if (prefixsum[i] == suffixprod[i])
                return i;
        }
        return -1;
    }
};