class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = strs[0];
        int n = strs.size();
        for (int i = 1; i < n; i++) {
            int l1 = pre.length();
            string s = strs[i];
            int l2 = s.length();
            int j = 0;
            int k = 0;
            string g = "";
            while (j < l1 && k < l2) {
                char ch1 = pre.at(j);
                char ch2 = s.at(k);
                if (ch1 == ch2) {
                    g.push_back(ch1);
                } else {
                    break;
                }
                j++;
                k++;
            }
            if (g.length() == 0)
                return "";
            pre = g;
        }
        return pre;
    }
};