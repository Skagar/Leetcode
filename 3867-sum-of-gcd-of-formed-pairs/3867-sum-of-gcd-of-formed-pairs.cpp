class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long n = nums.size();
        long long maxi = LLONG_MIN;
        vector<long long> prefixGcd(n);
        for (long long i = 0; i < n; i++) {
            maxi = max(maxi, (long long)nums[i]);
            prefixGcd[i] = gcd(maxi, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long i = 0;
        long long j = n - 1;
        long long sum = 0;
        while (i < j) {
            sum += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};