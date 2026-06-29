class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int len = word.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            string s = patterns[i];
            for (int i = 0; i < len; i++) {
                bool flag = false;
                string str = "";
                for (int j = i; j < len; j++) {
                    str += word[j];
                    if (s == str) {
                        flag = true;
                        cnt++;
                        break;
                    }
                }
                if (flag == true)
                    break;
            }
        }
        return cnt;
    }
};