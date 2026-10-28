class Solution {
private:
    void caldiv(int& n, vector<int>& div) {
        for (int i = 1; i <= n; i++) {
            if (n % i == 0)
                div.push_back(i);
        }
    }
    bool checksorted(vector<int>& nums) {
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> div;
        int sum = 0;
        caldiv(n, div);
        for (int i = 0; i < div.size(); i++) {
            if (div[i] == 1) {
                if (checksorted(nums))
                    sum += div[i];
            } else {
                int prevmax = INT_MIN;
                int currmin = INT_MAX;
                bool flag = true;
                int l = 0;
                int r = l + div[i] - 1;
                for (int j = l; j <= r; j++) {
                    prevmax = max(prevmax, nums[j]);
                }
                int iter = 1;
                while (r < n) {
                    int cnt = 0;
                    for (int j = l; j <= r; j++) {
                        if (nums[j] > nums[((j + 1) % div[i]) + l])
                            cnt++;
                    }
                    if (cnt > 1) {
                        flag = false;
                        break;
                    }
                    if (iter > 1) {
                        for (int j = l; j <= r; j++) {
                            currmin = min(currmin, nums[j]);
                        }
                        if (currmin < prevmax) {
                            flag = false;
                            break;
                        } else {
                            for (int j = l; j <= r; j++) {
                                prevmax = max(prevmax, nums[j]);
                            }
                            currmin = INT_MAX;
                        }
                    }
                    iter++;
                    l = r + 1;
                    r = l + div[i] - 1;
                }
                if (flag == true) {
                    sum += div[i];
                }
            }
        }
        return sum;
    }
};