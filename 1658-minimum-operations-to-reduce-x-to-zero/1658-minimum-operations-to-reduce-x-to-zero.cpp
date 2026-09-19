class Solution {
    /* int countmin(int s, int e, int& n, vector<int>& nums, int x) {
         if (x < 0)
             return 1e9;
         if (x == 0)
             return 0;
         if (s > e)
             return 1e9;
         int tk1 = 1e9;
         int tk2 = 1e9;
         tk1 = 1 + countmin(s + 1, e, n, nums, x - nums[s]);
         tk2 = 1 + countmin(s, e - 1, n, nums, x - nums[e]);
         return min(tk1, tk2);
     }*/

public:
    int minOperations(vector<int>& nums, int x) {
        // int n = nums.size();
        /*int val = countmin(0, n - 1, n, nums, x);
        if (val >= 1e9)
            return -1;
        return val;*/
        int n = nums.size();
        // M2 USING PREFIX AND SUFFIX SUM

        /*map<long long, int> mpre;
        map<long long, int> msuf;
        long long presum = 0;
        long long sufsum = 0;
        mpre[0] = 0;
        msuf[0] = 0;
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            mpre[presum] = i + 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            sufsum += nums[i];
            msuf[sufsum] = n - i;
        }
        int ans = INT_MAX;
        if (mpre.find(x) != mpre.end())
            ans = min(ans, mpre[x]);
        if (msuf.find(x) != msuf.end())
            ans = min(ans, msuf[x]);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            long long diff = (long long)x - sum;
            if (msuf.find(diff) != msuf.end()) {
                int prefixLen = i + 1;
                int suffixLen = msuf[diff];
                int suffixStart = n - suffixLen;
                if (suffixStart > i)
                    ans = min(ans, prefixLen + suffixLen);
            }
        }
        return ans == INT_MAX ? -1 : ans;*/
        int maxlen = INT_MIN;
        long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);
        long long xVal = (long long)x;
        long long remSum = totalSum - xVal;
        if (remSum < 0)
            return -1;
        if (remSum == 0)
            return n;
        long long sum = 0;
        int l = 0;
        int r = 0;
        while (r < n) {
            sum += (long long)nums[r];
            while (l < r && sum > remSum) {
                sum -= nums[l++];
            }
            if (sum == remSum) {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen == INT_MIN ? -1 : (n - maxlen);
    }
};