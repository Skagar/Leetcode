class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int diff = sum - k;
            if (sum == k)
                cnt++;
            if (!mp.empty() && mp.find(diff) != mp.end()) {
                cnt+=mp[diff];
            }
                mp[sum]++;
        }
        return cnt;
    }
};