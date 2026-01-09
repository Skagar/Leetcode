class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!mp.empty()) {
                if (mp.find(nums[i]) != mp.end()) {
                    int diff = abs(mp[nums[i]] - i);
                    if (diff <= k)
                        return true;
                mp[nums[i]]=i;
                }
                else
                mp[nums[i]]=i;
            } else {
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};