class Solution {
private:
    int getproduct(int m) {
        int p = 1;
        while (m != 0) {
            p = p * (m % 10);
            m = m / 10;
        }
        return p;
    }

public:
    int smallestNumber(int n, int t) {
        while (true) {
            int prod = getproduct(n);
            if (prod % t == 0)
                return n;
            n++;
        }
    }
};