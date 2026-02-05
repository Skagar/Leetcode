class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            if (ele > 0) {
                int j = (i + ele) % n;
                result[i] = nums[j];
            } else if (ele < 0) {
                int j = ((i + nums[i]) % n + n) % n;
                result[i] = nums[j];
            } else {
                result[i] = nums[i];
            }
        }
        return result;
    }
};