class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int len = 0;
            long long maxsum = (long long)queries[i];
            long long sum = 0;
            int j = 0;
            while (j < n) {
                if (sum + (long long)nums[j] <= maxsum) {
                    len++;
                    sum += (long long)nums[j];
                } else
                    break;
                j++;
            }
            ans[i] = len;
        }
        return ans;
    }
};