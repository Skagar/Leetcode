class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        while (sum > 0) {
            if (sum - 9 > 0) {
                ans += '9';
                sum = sum - 9;
            } else {
                ans += to_string(sum);
                sum = 0;
            }
        }
        if (ans.length() > num)
            return "";
        while (ans.length() < num) {
            ans += '0';
        }
        return ans;
    }
};