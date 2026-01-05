class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] == nums2[j]) {
                if (ans.empty())
                    ans.push_back(nums1[i]);
                else {
                    if (ans.back() != nums1[i])
                        ans.push_back(nums1[i]);
                }
                i++;
                j++;
            } else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        return ans;
    }
};