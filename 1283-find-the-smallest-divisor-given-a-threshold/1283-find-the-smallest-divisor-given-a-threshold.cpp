class Solution {
    long long calthresh(vector<int>& nums, int n, int div) {
        long long t = 0;
        for (int i = 0; i < n; i++) {
            t += ceil((double)nums[i] / (double)div);
        }
        return t;
    }

public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int s = 1;
        int e = *max_element(nums.begin(), nums.end());
        long long th = threshold;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (calthresh(nums, n, m) > th)
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
};