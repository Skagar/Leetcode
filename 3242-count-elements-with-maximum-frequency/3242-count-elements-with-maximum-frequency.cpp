class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        map<int, int>::iterator it;
        int maxi = INT_MIN;
        for (it = mp.begin(); it != mp.end(); it++) {
            maxi = max(it->second, maxi);
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            if (it->second == maxi)
                cnt += maxi;
        }
        return cnt;
    }
};