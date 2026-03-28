class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        long long fivecnt = 0;
        long long tencnt = 0;
        for (long long i = 0; i < bills.size(); i++) {
            int amt = bills[i];
            if (amt == 5)
                fivecnt++;
            else if (amt == 10) {
                tencnt++;
                if (fivecnt > 0)
                    fivecnt--;
                else
                    return false;
            } else if (amt == 20) {
                if (fivecnt > 0 && tencnt > 0) {
                    fivecnt--;
                    tencnt--;
                } else if (tencnt == 0 && fivecnt >= 3) {
                    fivecnt -= 3;
                } else
                    return false;
            }
        }
        return true;
    }
};