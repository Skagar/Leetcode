class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int cnt = 0;
        int m = n - 1;
        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            sum = sum - ele;
            if (double(ele) > ((double)sum / (double)m)) {
                cnt++;
            }
            m--;
        }
        return cnt;
    }
};