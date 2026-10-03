class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if (len == 0)
            return 0;
        int ocnt = 0;
        int ccnt = 0;
        int maxi = INT_MIN;
        for (int i = 0; i < len; i++) {
            char ch = s[i];
            if (ocnt > ccnt) {
                if (ch == '(') {
                    ocnt++;
                } else {
                    ccnt++;
                }
            } else if (ocnt == ccnt) {
                if (ch == '(') {
                    ocnt++;
                } else {
                    ocnt = 0;
                    ccnt = 0;
                }
            }
            if (ocnt == ccnt) {
                maxi = max(maxi, ccnt + ocnt);
            }
        }
        ocnt = 0;
        ccnt = 0;
        for (int i = len - 1; i >= 0; i--) {
            char ch = s[i];
            if (ocnt < ccnt) {
                if (ch == '(') {
                    ocnt++;
                } else {
                    ccnt++;
                }
            } else if (ocnt == ccnt) {
                if (ch == ')') {
                    ccnt++;
                } else {
                    ocnt = 0;
                    ccnt = 0;
                }
            }
            if (ocnt == ccnt) {
                maxi = max(maxi, ccnt + ocnt);
            }
        }
        return maxi;
    }
};