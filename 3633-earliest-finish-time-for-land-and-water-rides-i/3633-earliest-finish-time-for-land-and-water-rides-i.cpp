class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = landStartTime[i] + landDuration[i];
            for (int j = 0; j < m; j++) {
                if (waterStartTime[j] <= sum) {
                    ans = min(ans, sum + waterDuration[j]);
                } else {
                    ans = min(ans, sum + waterDuration[j] +
                                       (waterStartTime[j] - sum));
                }
            }
        }
        for (int i = 0; i < m; i++) {
            int sum = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < n; j++) {
                if (landStartTime[j] <= sum) {
                    ans = min(ans, sum + landDuration[j]);
                } else {
                    ans = min(ans,
                              sum + landDuration[j] + (landStartTime[j] - sum));
                }
            }
        }
        return ans;
    }
};