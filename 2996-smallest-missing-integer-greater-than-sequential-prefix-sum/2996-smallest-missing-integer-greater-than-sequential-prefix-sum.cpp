class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int i = 1;
        while (i < n) {
            if (nums[i] == (nums[i - 1] + 1))
                sum += nums[i++];
            else
                break;
        }
        i = sum;
        while (true) {
            bool flag = false;
            for (int j = 0; j < n; j++) {
                if (nums[j] == i) {
                    flag = true;
                    break;
                }
            }
            if (flag == false)
                return i;
            i++;
        }
        return -1;
    }
};