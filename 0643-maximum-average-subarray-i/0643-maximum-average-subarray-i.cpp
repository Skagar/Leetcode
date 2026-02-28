class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        long long sum = 0;
        double maxi = (double)INT_MIN;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            if ((r - l + 1) >= k) {
                while ((r - l + 1) != k) {
                    sum -= nums[l];
                    l++;
                }
                double avg = (double)sum / (double)k;
                maxi = max(avg, maxi);
            }
        }
        return maxi;
    }
};