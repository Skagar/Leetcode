class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        long long sumN = (n * (n + 1)) / 2;
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        long long sumsqN = (1LL * n * (n + 1) * ((2 * n) + 1)) / 6;
        long long sumsq = 0LL;
        for (int i = 0; i < n; i++) {
            long long x = (long long)nums[i];
            sumsq += (1LL * x * x);
        }
        long long v1 = sumN - sum;
        long long v2 = (sumsqN - sumsq) / v1;
        long long y = (v1 + v2) / 2;
        long long x = v2 - y;
        ans.push_back(x);
        ans.push_back(y);
        return ans;
    }
};