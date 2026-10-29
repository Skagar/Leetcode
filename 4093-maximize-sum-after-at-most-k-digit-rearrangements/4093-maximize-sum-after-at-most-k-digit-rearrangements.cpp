class Solution {
private:
    int convert(int ele) {
        string s = to_string(ele);
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        return stoi(s);
    }

public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            int ele = convert(nums[i]);
            v[i] = {ele - nums[i], nums[i]};
        }
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--) {
            if (k > 0) {
                ans += (1LL * (v[i].first + v[i].second));
                k--;
            } else {
                ans += (1ll * (v[i].second));
            }
        }
        return ans;
    }
};