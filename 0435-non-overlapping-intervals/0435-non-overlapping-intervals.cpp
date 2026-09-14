class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int c = 0;
            if (intervals[i][0] == 1e9 && intervals[i][1] == 1e9)
                continue;
            else {
                int e = intervals[i][1];
                int j = i + 1;
                while (j < n && e > intervals[j][0]) {
                    int e2 = intervals[j][1];
                    if (e <= e2) {
                        intervals[j][0] = 1e9;
                        intervals[j][1] = 1e9;
                        cnt++;
                    } else {
                        c = 1;
                        break;
                    }
                    j++;
                }
                cnt += c;
            }
        }
        return cnt;
    }
};