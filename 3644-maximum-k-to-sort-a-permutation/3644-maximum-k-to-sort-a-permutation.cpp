class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        int ans = ~0;
        for (int i = 0; i < n; i++) {
            if (temp[i] != nums[i]) {
                cout << nums[i] << " ";
                ans = ans & nums[i];
                cout << ans << endl;
            }
        }
        if (ans == ~0)
            return 0;
        return ans;
    }
};