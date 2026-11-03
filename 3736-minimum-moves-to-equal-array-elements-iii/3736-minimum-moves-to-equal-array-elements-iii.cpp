class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (nums[n - 1] - nums[i]);
        }
        return sum;
    }
};