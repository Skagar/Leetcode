class Solution {
    int check(int k, vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            if (nums[m] == k)
                return m;
            else if (nums[m] > k)
                e = m - 1;
            else
                s = m + 1;
        }
        return -1;
    }

public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int val = k;
        while (true) {
            int found = check(k, nums);
            if (found == -1)
                return k;
            k += val;
        }
        return -1;
    }
};