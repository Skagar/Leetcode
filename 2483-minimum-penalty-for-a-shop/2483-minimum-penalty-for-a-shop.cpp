class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<long long> ycnt(n + 1, 0);
        vector<long long> ncnt(n + 1, 0);
        int ind = -1;
        long long penalty = LLONG_MAX;
        for (int i = n - 1; i >= 0; i--) {
            if (customers[i] == 'Y')
                ycnt[i] = 1 + ycnt[i + 1];
            else
                ycnt[i] = ycnt[i + 1];
        }
        for (int i = 0; i < n; i++) {
            if (customers[i] == 'N')
                ncnt[i + 1] = 1 + ncnt[i];
            else
                ncnt[i + 1] = ncnt[i];
        }
        for (int i = 0; i <= n; i++) {
            long long p = ycnt[i] + ncnt[i];
            if (p < penalty) {
                penalty = p;
                ind = i;
            }
        }
        return ind;
    }
};