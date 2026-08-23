class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        long long lsum = 0LL;
        long long rsum = 0LL;
        int lcnt = 0;
        int rcnt = 0;
        int tcnt = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] != '?') {
                lsum += (long long)(num[i] - '0');
            } else
                lcnt++;
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] != '?') {
                rsum += (long long)(num[i] - '0');
            } else
                rcnt++;
        }

        if ((lcnt + rcnt) % 2 != 0)
            return true;

        return lsum + (lcnt - rcnt) * 9 / 2 != rsum;
    }
};