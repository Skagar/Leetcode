class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ele1 = -1, ele2 = -1;
        int ind1 = -1, ind2 = -1;
        if ((m + n) % 2 == 0) {
            ind2 = (m + n) / 2;
            ind1 = ind2 - 1;
        } else
            ind2 = (m + n) / 2;
        while (i < n && j < m) {
            if (ind1 == cnt)
                ele1 = min(nums1[i], nums2[j]);
            if (ind2 == cnt)
                ele2 = min(nums1[i], nums2[j]);
            if (nums1[i] < nums2[j]) {
                i++;
                cnt++;
            } else {
                j++;
                cnt++;
            }
        }
        while (i < n) {
            if (ind1 == cnt)
                ele1 = nums1[i];
            if (ind2 == cnt)
                ele2 = nums1[i];
            i++;
            cnt++;
        }
        while (j < m) {
            if (ind1 == cnt)
                ele1 = nums2[j];
            if (ind2 == cnt)
                ele2 = nums2[j];
            j++;
            cnt++;
        }
        if (ind1 == -1)
            return (double)ele2;

        return ((double)ele1 + (double)ele2) / (double)2;
    }
};