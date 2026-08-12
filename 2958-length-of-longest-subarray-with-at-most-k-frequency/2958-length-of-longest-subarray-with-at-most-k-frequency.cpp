class Solution {
    /*bool check(map<int, int>& mp, int& k) {
        for (auto i : mp) {
            if (i.second > k)
                return false;
        }
        return true;
    }*/

public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1)
            return 1;
        map<int, int> mp;
        int l = 0, r = 0;
        int maxlen = INT_MIN;
        int maxfq = INT_MIN;
        while (l <= r && r < n) {
            mp[nums[r]]++;
            maxfq = max(maxfq, mp[nums[r]]);
            if (maxfq <= k) {
                maxlen = max(maxlen, r - l + 1);
            } else {
                while (l <= r && maxfq > k) {
                    mp[nums[l]]--;
                    if (mp[nums[l]] >= k)
                        maxfq = min(maxfq, mp[nums[l]]);
                    if (mp[nums[l]] == 0)
                        mp.erase(nums[l]);
                    l++;
                }
            }
            r++;
        }
        return maxlen;
    }
};