class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for (auto i : mp) {
            int num = i.first + 1;
            if (mp.find(num) != mp.end()) {
                ans = max(ans, mp[num] + i.second);
            }
        }
        if (ans == INT_MIN)
            return 0;
        return ans;
    }
};