class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n = arrivalTime.size();
        sort(lights.begin(), lights.end());
        long long ans = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            long long ele = (long long)arrivalTime[i];
            long long rem = ele % (long long)period;
            int s = 0;
            int e = lights.size() - 1;
            if (rem >= (long long)lights[e]) {
                long long diff = (long long)period - rem;
                ans = max(ans, diff);
            } else if (rem < (long long)lights[s])
                continue;
            else {
                bool flag = false;
                while (s <= e) {
                    int m = s + (e - s) / 2;
                    long long val = (long long)lights[m];
                    if (val <= rem)
                        s = m + 1;
                    else {
                        flag = true;
                        break;
                    }
                }
                if (flag == false) {
                    long long diff = (long long)period - rem;
                    ans = max(ans, diff);
                }
            }
        }
        return ans;
    }
};