class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n=intervals.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int e = intervals[i][1];
            for (int j = i + 1; j < n; j++) {
                if (e >= intervals[j][0])
                    cnt++;
                else
                    break;
            }
        }
        return cnt;
    }
};