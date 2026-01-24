class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = nums.size() - 1;
        int ans = INT_MIN;
        int sum = 0;
        while (i < j) {
            sum = nums[i] + nums[j];
            ans = max(ans, sum);
            i++;
            j--;
        }
        return ans;
    }
};