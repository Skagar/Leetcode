class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        int diff = INT_MAX;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                sum = nums[i];
                sum = sum + nums[j] + nums[k];
                if (sum > target) {
                    int dif = abs(sum - target);
                    if (diff > dif) {
                        diff = dif;
                        ans = sum;
                    }
                    k--;
                } else if (sum < target) {
                    int dif = abs(sum - target);
                    if (diff > dif) {
                        diff = dif;
                        ans = sum;
                    }
                    j++;
                } else {
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                    return sum;
                }
            }
        }
        return ans;
    }
};