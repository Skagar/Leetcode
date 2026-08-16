class Solution {
private:
    int countsubarr(vector<int>& nums, long long m) {
        long long sum = 0;
        int cnt = 1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (sum + (long long)nums[i] <= m) {
                sum += (long long)nums[i];
            } else {
                cnt++;
                sum = (long long)nums[i];
            }
        }
        return cnt;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        long long s = *max_element(nums.begin(), nums.end());
        long long e = accumulate(nums.begin(), nums.end(), 0LL);
        while (s <= e) {
            long long m = s + (e - s) / 2;
            int subarr = countsubarr(nums, m);
            if (subarr > k)
                s = m + 1;
            else
                e = m - 1;
        }
        return s;
    }
};