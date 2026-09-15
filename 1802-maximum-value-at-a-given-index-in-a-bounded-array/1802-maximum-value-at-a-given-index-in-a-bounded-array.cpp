class Solution {
    long long check(long long& m, long long& ind, int& n) {
        long long sum = m;
        long long lind = ind - 1;
        long long rind = ind + 1;
        long long leftelements = lind + 1;
        long long rightelements = n - rind;
        long long lval;
        long long rval;
        if (m > 1) {
            lval = m - 1;
            rval = m - 1;
        } else {
            lval = m;
            rval = m;
        }
        if (leftelements >= lval) {
            sum += (lval * (lval + 1)) / 2 + (leftelements - lval);
        } else {
            long long rem = lval - leftelements;
            sum += (lval * (lval + 1)) / 2 - (rem * (rem + 1)) / 2;
        }
        if (rightelements >= rval) {
            sum += (rval * (rval + 1)) / 2 + (rightelements - rval);
        } else {
            long long rem = rval - rightelements;
            sum += (rval * (rval + 1)) / 2 - (rem * (rem + 1)) / 2;
        }
        return sum;
    }

public:
    int maxValue(int n, int index, int maxSum) {
        long long s = 0;
        long long e = maxSum;
        long long ans = -1;
        long long ind = (long long)index;
        while (s <= e) {
            long long m = s + (e - s) / 2;
            long long sum = check(m, ind, n);
            if (sum == maxSum)
                return m;
            else if (sum > maxSum)
                e = m - 1;
            else {
                ans = m;
                s = m + 1;
            }
        }
        return ans;
    }
};