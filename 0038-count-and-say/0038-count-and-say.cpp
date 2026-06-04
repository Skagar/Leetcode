class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; i++) {
            int len = s.length();
            string str = "";
            int j = 0;
            int cnt = 1;
            while (j < len) {
                if ((j + 1 < len) && (s[j] == s[j + 1])) {
                    cnt++;
                    j++;
                } else {
                    str += to_string(cnt);
                    str.push_back(s[j]);
                    cnt = 1;
                    j++;
                }
            }
            cout << str << endl;
            s = str;
        }
        return s;
    }
};