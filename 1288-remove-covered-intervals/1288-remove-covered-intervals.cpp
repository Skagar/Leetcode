class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for(auto i:intervals)
        {
            for(auto j:i)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
        int n = intervals.size();
        int i = 0;
        int cnt = 0;
        while (i < n) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            int j = i + 1;
            while (j < n) {
                int c = intervals[j][0];
                int d = intervals[j][1];
                if (c >= a && d <= b) {
                    intervals[j][0] = -1;
                    intervals[j][1] = -1;
                    j++;
                } else if (c == a && d > b) {
                    intervals[i][0] = -1;
                    intervals[i][1] = -1;
                    break;
                }
                else
                break;
            }
            i = j;
        }
        for (int j = 0; j < n; j++) {
            if (intervals[j][0] != -1)
                cnt++;
        }
        return cnt;
    }
};