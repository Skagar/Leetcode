class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int len = s.length();
        string ans = "";
        int i = 0;
        unordered_map<string, string> mp;
        int n = knowledge.size();
        for (int i = 0; i < n; i++) {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        while (i < len) {
            if (s[i] != '(' && s[i] != ')') {
                ans += s[i];
            } else if (s[i] == '(') {
                string key = "";
                int j = i + 1;
                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }
                if (mp.find(key) != mp.end()) {
                    ans += mp[key];
                } else
                    ans += '?';
                i = j;
            }
            i++;
        }
        return ans;
    }
};