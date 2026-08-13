class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % 2 == 0) {
                sum += (long long)nums[i];
            }
        }
        for (int i = 0; i < m; i++) {
            long long val = (long long)queries[i][0];
            int ind = queries[i][1];
            long long ele = (long long)nums[ind];
            long long temp = ele + val;
            if (ele % 2 == 0) {
                if (temp % 2 == 0)
                    sum += val;
                else
                    sum -= ele;
                ans[i] = (int)sum;
                nums[ind] = (int)temp;
            } else {
                if (temp % 2 == 0)
                    sum += temp;
                ans[i] = (int)sum;
                nums[ind] = (int)temp;
            }
        }
        return ans;
    }
};