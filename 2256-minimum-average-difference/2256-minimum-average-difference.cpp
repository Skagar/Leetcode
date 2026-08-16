class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long ans = LLONG_MAX;
        int ind = -1;
        long long psum = 0;
        for (int i = 0; i < n; i++) {
            int pele = i + 1;
            int sele = n - pele;
            psum += (long long)nums[i];
            long long ssum = totalSum - psum;
            long long avg1;
            long long avg2;
            if (pele == 0)
                avg1 = 0;
            else
                avg1 = psum / (long long)pele;
            if (sele == 0)
                avg2 = 0;
            else
                avg2 = ssum / (long long)sele;
            long long diff = abs(avg1 - avg2);
            if (ans > diff) {
                ind = i;
                ans = diff;
            }
        }
        return ind;
    }
};