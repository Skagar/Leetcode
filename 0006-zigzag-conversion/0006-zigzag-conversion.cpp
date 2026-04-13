class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> temp(numRows, "");
        string ans = "";
        int len = s.length();
        int n = 0, m = numRows - 1;
        for (int i = 0; i < len; i++) {
            if (n < numRows && m == numRows - 1) {
                temp[n].push_back(s[i]);
                n++;
            } else {
                m--;
                temp[m].push_back(s[i]);
                if (m == 0) {
                    m = numRows - 1;
                    n = 1;
                }
            }
        }
        for (int i = 0; i < numRows; i++) {
            for (auto j : temp[i])
                ans.push_back(j);
        }
        return ans;
    }
};