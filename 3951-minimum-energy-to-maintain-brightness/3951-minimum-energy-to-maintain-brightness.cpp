class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int minbulbs = ceil((double)brightness/3);
        int m = intervals.size();
        int i = 0;
        int j = 1;
        sort(intervals.begin(), intervals.end());
        while (i < m && j < m) {
            if (intervals[j][0] <= intervals[i][1]) {
                intervals[i][1] = max(intervals[i][1], intervals[j][1]);
                intervals[j][0] = -1;
                intervals[j][1] = -1;
                j++;
            } else {
                i = j;
                j = j + 1;
            }
        }
        long long len = 0;
        for (int i = 0; i < m; i++) {
            if (intervals[i][0] != -1 && intervals[i][1] != -1) {
                len += (long long)(intervals[i][1] - intervals[i][0] + 1);
            }
        }
        return minbulbs * len * 1LL;
    }
};