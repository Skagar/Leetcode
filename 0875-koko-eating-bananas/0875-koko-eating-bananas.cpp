class Solution {
private:
    long long checkhrs(vector<int>& piles, long long k) {
        long long n = piles.size();
        long long cnt = 0;
        for (long long i = 0; i < n; i++) {
            cnt += ceil((double)piles[i] / (double)k);
        }
        return cnt;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long s = 1;
        long long e = *max_element(piles.begin(), piles.end());
        while (s <= e) {
            long long m = s + (e - s) / 2;
            long long hrs = checkhrs(piles, m);
            if (hrs > (long long)h) {
                s = m + 1;
            } else if (hrs <= h)
                e = m - 1;
        }
        return s;
    }
};