class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 2;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        for (int i = 2; i < n; i++) {
            if (nums[i] == nums[k - 2])
                continue;
            else {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};