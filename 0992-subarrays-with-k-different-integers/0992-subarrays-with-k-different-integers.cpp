class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        map<int, int> fq;
        int cnt = 0;
        while (r < n) {
            fq[nums[r]]++;
            while (l <= r && fq.size() == k) {
                cnt += (n - r);
                fq[nums[l]]--;
                if (fq[nums[l]] == 0)
                    fq.erase(nums[l]);
                l++;
            }
            r++;
        }
        l = 0;
        r = 0;
        map<int, int> fq1;
        int cnt1 = 0;
        while (r < n) {
            fq1[nums[r]]++;
            while (l <= r && fq1.size() > k) {
                cnt1 += (n - r);
                fq1[nums[l]]--;
                if (fq1[nums[l]] == 0)
                    fq1.erase(nums[l]);
                l++;
            }
            r++;
        }

        return cnt - cnt1;
    }
};