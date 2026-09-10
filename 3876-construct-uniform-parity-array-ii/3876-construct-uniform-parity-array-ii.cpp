class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        int oddcnt = 0;
        int evencnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0)
                evencnt++;
            else
                oddcnt++;
        }
        if ((evencnt == 0 && oddcnt != 0) || (evencnt != 0 && oddcnt == 0))
            return true;
        bool flag = false;
        if (nums1[0] % 2 == 0)
            flag = true;
        if (flag == true) {
            for (int i = 1; i < n; i++) {
                if (nums1[i] % 2 != 0)
                    return false;
            }
        } else {
            return true;
        }
        return true;
    }
};