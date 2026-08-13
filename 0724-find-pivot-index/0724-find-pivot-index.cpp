class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        vector<int> pref(n);
        vector<int> suff(n);
        pref[0] = 0;
        suff[n - 1] = 0;
        int psum = nums[0];
        int ssum = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = psum;
            psum += nums[i];
        }
        for (int i = n - 2; i >= 0; i--) {
            suff[i] = ssum;
            ssum += nums[i];
        }
        for (int i = 0; i < n; i++) {
            if (pref[i] == suff[i])
                return i;
        }
        return -1;
    }
};