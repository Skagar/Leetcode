class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int m = nums.size();
        int i = 0;
        int j = n;
        vector<int> ans;
        while (j < m) {
            ans.push_back(nums[i++]);
            ans.push_back(nums[j++]);
        }
        return ans;
    }
};