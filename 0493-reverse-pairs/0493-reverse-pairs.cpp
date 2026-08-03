class Solution {
private:
    void merge(int s, int e, vector<int>& nums, int& cnt) {
        int m = s + (e - s) / 2;
        vector<int> temp;
        int i = s;
        int j = m + 1;
        while (i <= m && j <= e) {
            if ((long long)nums[i] > (2LL * (long long)nums[j])) {
                cnt += (m - i + 1);
                j++;
            } else {
                i++;
            }
        }
        i = s;
        j = m + 1;
        while (i <= m && j <= e) {
            if (nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else if (nums[i] == nums[j]) {
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                i++;
                j++;
            } else if (nums[i] > nums[j]) {
                temp.push_back(nums[j]);
                j++;
            }
        }
        while (i <= m) {
            temp.push_back(nums[i]);
            i++;
        }
        while (j <= e) {
            temp.push_back(nums[j]);
            j++;
        }
        int ind = 0;
        for (int k = s; k <= e; k++) {
            nums[k] = temp[ind++];
        }
    }
    void countpairs(int s, int e, vector<int>& nums, int& cnt) {
        if (s >= e)
            return;
        int m = s + (e - s) / 2;
        countpairs(s, m, nums, cnt);
        countpairs(m + 1, e, nums, cnt);
        merge(s, e, nums, cnt);
    }

public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        /* int cnt = 0;
         for (int i = 0; i < n; i++) {
             for (int j = n - 1; j > i; j--) {
                 if ((long long)nums[i] > (1LL * 2 * (long long)nums[j]))
                     cnt++;
             }
         }
         return cnt;*/
        countpairs(0, n - 1, nums, cnt);
        return cnt;
    }
};