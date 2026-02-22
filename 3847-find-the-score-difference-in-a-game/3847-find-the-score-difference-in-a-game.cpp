class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int active = 0;
        int fcnt = 0;
        int scnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int ele = nums[i];
            if ((i % 6 != 5) && (ele % 2 == 0)) // even but not 6th game
            {
                if (active == 0)
                    fcnt += ele;
                else
                    scnt += ele;
            } else if ((i % 6 != 5) && (ele % 2 != 0)) { // odd but not 6th game
                if (active == 0) {
                    scnt += ele;
                    active = 1;
                } else {
                    fcnt += ele;
                    active = 0;
                }
            } else if ((i % 6 == 5) && (ele % 2 != 0)) { // odd but 6th game
                if (active == 0)
                    fcnt += ele;
                else
                    scnt += ele;
            } else if ((i % 6 == 5) && (ele % 2 == 0)) { // even but 6th game
                if (active == 0) {
                    scnt += ele;
                    active = 1;
                } else {
                    fcnt += ele;
                    active = 0;
                }
            }
        }
        return (fcnt - scnt);
    }
};