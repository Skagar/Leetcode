class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n / 2 && n % 2 != 0) {
            vector<int> ans(n, -1);
            return ans;
        }
        if (k >= n / 2 && n % 2 == 0) {
            vector<int> ans(n, -1);
            return ans;
        }
        if (k == 0)
            return nums;
        vector<int> ans(n, -1);
        int ind = k;
        long long sum = 0;
        long long range = ((2 * k) + 1);
        for (int i = ind - k; i <= ind + k; i++) {
            sum += (long long)nums[i];
        }
        ans[ind] = sum / range;
        int l = ind - k;
        int r = ind + k;
        ind = ind + 1;
        while (r < n) {
            sum = sum - (long long)nums[l];
            l++;
            r++;
            if (r >= n)
                break;
            sum += (long long)nums[r];
            ans[ind] = sum / range;
            ind++;
        }
        return ans;
    }
};