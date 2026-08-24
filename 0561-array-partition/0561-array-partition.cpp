class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long ans = 0LL;
        int n = nums.size();
        for (int i = 1; i < n; i = i + 2) {
            ans += (long long)min(nums[i], nums[i - 1]);
        }
        return ans;
    }
};