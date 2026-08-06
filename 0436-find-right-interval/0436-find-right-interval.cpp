class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int m = intervals.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int minval = INT_MAX;
            int ind = -1;
            for (int j = 0; j < m; j++) {
                if (intervals[j][0] >= intervals[i][1]) {
                    if (intervals[j][0] < minval) {
                        minval = intervals[j][0];
                        ind = j;
                    }
                }
            }
            ans[i] = ind;
        }
        return ans;
    }
};