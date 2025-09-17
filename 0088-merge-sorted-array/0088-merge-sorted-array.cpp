class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        vector<int> temp;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                temp.push_back(nums1[i]);
                i++;
            } else if (nums1[i] > nums2[j]) {
                temp.push_back(nums2[j]);
                j++;
            } else {
                temp.push_back(nums1[i]);
                temp.push_back(nums1[i]);
                i++;
                j++;
            }
        }
        while (i < m) {
            temp.push_back(nums1[i]);
            i++;
        }
        while (j < n) {
            temp.push_back(nums2[j]);
            j++;
        }
        nums1.clear();
        for (int k = 0; k < temp.size(); k++) {
            nums1.push_back(temp[k]);
        }
    }
};