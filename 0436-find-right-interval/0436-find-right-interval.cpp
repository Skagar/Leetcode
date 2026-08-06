class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        /* int m = intervals.size();
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
         return ans;*/
        int m = intervals.size();
        vector<int> ans(m);
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; i++) {
            int u = intervals[i][0];
            int v = intervals[i][1];
            mp[{u, v}] = i;
        }
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < m; i++) {
            int minval = INT_MAX;
            int ind = -1;
            int s = i;
            int e = m - 1;
            int u = intervals[i][0];
            int v = intervals[i][1];
            while (s <= e) {
                int m = s + (e - s) / 2;
                if (intervals[m][0] >= v) {
                    if (intervals[m][0] < minval) {
                        minval = intervals[m][0];
                        ind = mp[{intervals[m][0], intervals[m][1]}];
                    }
                    e = m - 1;
                } else
                    s = m + 1;
            }
            ans[mp[{u, v}]] = ind;
        }
        return ans;
    }
};