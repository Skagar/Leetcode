class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0)
            return;
        int i = m - 1;
        int j = 0;
        while (i >= 0 && j < n) {
            if (nums1[i] > nums2[j]) {
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            } else
                j++;
        }
        for (int k = m; k < m + n; k++) {
            nums1[k] = nums2[k - m];
        }
       sort(nums1.begin(),nums1.end());
    }
};