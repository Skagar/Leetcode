class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> v(n, 1e9);
        int sum = 0;
        int l = 0;
        int r = 0;
        int ans = 1e9;
        int minlen = 1e9;
        while (r < n) {
            sum += arr[r];
            while (l <= r && sum > target) {
                sum -= arr[l];
                l++;
            }
            if (sum == target) {
                int len = r - l + 1;
                if (l > 0 && v[l - 1] != 1e9) {
                    ans = min(ans, len + v[l - 1]);
                }
                minlen = min(minlen, len);
            }
            v[r] = minlen;
            r++;
        }
        if (ans == 1e9)
            return -1;
        return ans;
    }
};