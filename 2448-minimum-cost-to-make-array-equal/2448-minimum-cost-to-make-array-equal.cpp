class Solution {
private:
    long long calCost(int val, vector<int>& nums, vector<int>& cost) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum +=((long long)abs(nums[i] - val) * (long long)cost[i]*1LL);
        }
        return sum;
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans = LLONG_MAX;
        int s = *min_element(nums.begin(), nums.end());
        int e = *max_element(nums.begin(), nums.end());
        while (s <= e) {
            int m = s + (e - s) / 2;
            long long costMid = calCost(m, nums, cost);
            long long costMid1 = calCost(m + 1, nums, cost);
            if (costMid1 > costMid) {
                ans = min(ans, costMid);
                e = m - 1;
            } else {
                ans = min(ans, costMid1);
                s = m + 1;
            }
        }
        return ans;
    }
};