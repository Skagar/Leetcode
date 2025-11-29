class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < k)
            return sum;
        if (sum % k == 0)
            return 0;
        else {
            return (sum % k);
        }
    }
};