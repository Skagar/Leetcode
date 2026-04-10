class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n) {
                if (nums[i] == nums[j])
                    break;
                else
                    j++;
            }
            int k = j + 1;
            while (k < n) {
                if (nums[j] == nums[k])
                    break;
                else
                    k++;
            }
            if (i < n && j < n && k < n) {
                int dist = abs(i - j) + abs(j - k) + abs(k - i);
                mini = min(mini, dist);
            }
        }
        if (mini != INT_MAX)
            return mini;
        return -1;
    }
};