class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                res.push_back(nums2[j]);
                j++;
            } else {
                res.push_back(nums1[i]);
                res.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        while (i < n1) {
            res.push_back(nums1[i]);
            i++;
        }
        while (j < n2) {
            res.push_back(nums2[j]);
            j++;
        }
        int r = res.size();
        if (r % 2 != 0) {
            return (double)res[(r / 2)];
        } else {
            double val = ((double)res[r / 2] +
                          (double)res[(double)(r-1) / (double)2]) /
                         (double)2;
            return val;
        }
    }
};