class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        int x, freqx, y = INT_MAX, freqy;
        for (auto i : mp) {
            x = i.first;
            freqx = i.second;
            break;
        }

        for (auto i : mp) {
            if (i.first > x && i.second != freqx) {
                y = min(y, i.first);
            }
        }
        if (y == INT_MAX) {
            return {-1, -1};
        }
        return {x, y};
    }
};