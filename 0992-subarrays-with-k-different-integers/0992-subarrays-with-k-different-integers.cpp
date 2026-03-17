class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        map<int, int> fq;
        int cnt = 0;
        while (r < n) {  //Subarrays that have K or less Distinct elements
            fq[nums[r]]++;
            while (l <= r && fq.size() > k) {
                fq[nums[l]]--;
                if (fq[nums[l]] == 0)
                    fq.erase(nums[l]);
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        l = 0;
        r = 0;
        map<int, int> fq1;
        int cnt1 = 0;
        while (r < n) {//Subarrays that have less than K Distinct elements
            fq1[nums[r]]++;
            while (l <= r && fq1.size() >= k) {
                fq1[nums[l]]--;
                if (fq1[nums[l]] == 0)
                    fq1.erase(nums[l]);
                l++;
            }
            cnt1 += (r - l + 1);
            r++;
        }

        return cnt - cnt1;
    }
};