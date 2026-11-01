class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long tsum = accumulate(nums.begin(), nums.end(), 0LL);
        long long insum = 1LL * n * nums[0];
        long long ans = tsum - insum;
        return ans;
    }
};