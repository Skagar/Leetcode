class Solution {
public:
    int mySqrt(int x) {
        long long s = 0;
        long long e = x;
        long long ans = -1;
        while (s <= e) {
            long long m = s + (e - s) / 2;
            long long sq = m * m;
            if (sq == (long long)x)
                return m;
            else if (sq > x) {
                ans = m - 1;
                e = m - 1;
            } else
                s = m + 1;
        }
        return ans;
    }
};