class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int j = i + 1;
        int k = i + 2;
        int ans = INT_MIN;
        while (k < n) {
            if ((nums[i] + nums[j]) > nums[k])
                ans = max(ans, nums[i] + nums[j] + nums[k]);
            i++;
            j++;
            k++;
        }
        if (ans == INT_MIN)
            return 0;
        return ans;
    }
};