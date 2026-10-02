class Solution {
    void generate(int ocnt, int ccnt, vector<string>& ans, string s) {
        if (ocnt == 0 && ccnt == 0) {
            ans.push_back(s);
            return;
        }
        if (ocnt > 0 && ocnt <= ccnt)
            generate(ocnt - 1, ccnt, ans, s + "(");
        if (ccnt >= ocnt)
            generate(ocnt, ccnt - 1, ans, s + ")");
        return;
    }

public:
    vector<string> generateParenthesis(int n) {
        int ocnt = n;
        int ccnt = n;
        vector<string> ans;
        string s = "";
        generate(ocnt, ccnt, ans, s);
        return ans;
    }
};