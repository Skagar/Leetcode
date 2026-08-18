class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<long long, long long> mp;
        mp[0] = 1;
        int n = nums.size();
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long)nums[i];
            long long rem = sum % (long long)k;
            if (rem < 0)
                rem = rem + (long long)k;
            if (mp.find(rem) != mp.end())
                ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};