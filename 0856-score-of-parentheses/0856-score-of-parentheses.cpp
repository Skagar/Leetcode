class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        vector<int> v;
        int sc = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                v.push_back(sc);
                sc = 0;
            } else {
                if (s[i - 1] == '(') {
                    sc = v.back() + 1;
                } else {
                    sc = v.back() + (2 * sc);
                }
                v.pop_back();
            }
        }
        return sc;
    }
};