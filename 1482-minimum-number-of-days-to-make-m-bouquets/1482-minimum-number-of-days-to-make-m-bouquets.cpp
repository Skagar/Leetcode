class Solution {
    long long countBouquets(long long days, vector<int>& bloomDay, int k) {
        long long n = bloomDay.size();
        long long cnt = 0;
        long long i = 0;
        long long cons = 0;
        for (i = 0; i < n; i++) {
            if ((long long)bloomDay[i] <= days)
                cons++;
            else
                cons = 0;
            if (cons == k) {
                cnt++;
                cons = 0;
            }
        }
        return cnt;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long n = bloomDay.size();
        if ((long long)m * (long long)k > n)
            return -1;
        long long e = *max_element(bloomDay.begin(), bloomDay.end());
        long long s = 1;
        while (s <= e) {
            long long mid = s + (e - s) / 2;
            long long bqcnt = countBouquets(mid, bloomDay, k);
            cout << mid << " " << bqcnt << endl;
            if (bqcnt >= m)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return s;
    }
};