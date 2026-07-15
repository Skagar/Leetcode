class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int m = n;
        int oddsum = 0;
        int oddcnt = 1;
        int evensum = 0;
        int evencnt = 2;
        while (m != 0) {
            oddsum += oddcnt;
            evensum += evencnt;
            oddcnt += 2;
            evencnt += 2;
            m--;
        }
        return gcd(evensum, oddsum);
    }
};