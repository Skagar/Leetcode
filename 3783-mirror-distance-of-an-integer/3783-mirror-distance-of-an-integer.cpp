class Solution {
public:
    int mirrorDistance(int n) {
        long long m = n;
        long long rev = 0;
        while (m != 0) {
            rev = (rev * 10) + (m % 10);
            m = m / 10;
        }
        return abs(n-rev);
    }
};