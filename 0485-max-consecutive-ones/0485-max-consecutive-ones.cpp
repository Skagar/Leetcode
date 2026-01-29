class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int maxi = INT_MIN;
        while (r < n) {
            if (nums[r] == 1)
                r++;
            else {
                maxi = max(maxi, r - l);
                l = r + 1;
                r++;
            }
        }
        maxi = max(maxi, r - l);
        return maxi;
    }
};