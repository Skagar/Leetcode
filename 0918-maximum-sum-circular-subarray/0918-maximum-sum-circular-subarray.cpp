class Solution {
private:
    long long calmaxsumsubarr(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long maxsum = LLONG_MIN;
        for (long long i = 0; i < n; i++) {
            sum += (long long)nums[i];
            maxsum = max(maxsum, sum);
            if (sum < 0)
                sum = 0;
        }
        return maxsum;
    }
    long long calminsumsubarr(vector<int>& nums) {
        long long n = nums.size();
        long long sum = 0;
        long long minsum = LLONG_MAX;
        for (long long i = 0; i < n; i++) {
            sum += (long long)nums[i];
            minsum = min(minsum, sum);
            if (sum > 0)
                sum = 0;
        }
        return minsum;
    }

public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // BF
        /* long long n = nums.size();
         long long maxsum = LLONG_MIN;
         long long i = 0;
         while (i < n) {
             long long j = i;
             long long sum = 0;
             long long range = i + n;
             while (j < range) {
                 long long ele = (long long)nums[j % n];
                 sum += ele;
                 maxsum = max(maxsum, sum);
                 if (sum < 0)
                     sum = 0;
                 j++;
             }
             i++;
         }
         return maxsum;*/

        long long n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long maxsum = calmaxsumsubarr(nums);
        long long cirsum = totalSum - calminsumsubarr(nums);
        if (maxsum > 0)
            return max(maxsum, cirsum);
        return maxsum;
    }
};