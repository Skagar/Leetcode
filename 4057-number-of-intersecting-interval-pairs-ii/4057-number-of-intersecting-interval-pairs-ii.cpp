class Solution {
    int findminind(int s, vector<vector<int>>& intervals, long long& end) {
        int e = intervals.size() - 1;
        while (s <= e) {
            int m = s + (e - s) / 2;
            long long ele = intervals[m][0];
            if (end >= ele)
                s = m + 1;
            else
                e = m - 1;
        }
        return e;
    }

public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            long long end = intervals[i][1];
            int ind = findminind(i + 1, intervals, end);
            if (ind > 0)
                cnt += ((long long)ind - (long long)i);
        }
        return cnt;
    }
};