class Solution {
public:
    string mergeCharacters(string s, int k) {
        vector<int> rem;
        map<char, int> m;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (m.find(s[i]) != m.end() && ((res.size() - m[s[i]]) <= k)) {
                continue;
            } else {
                res += s[i];
                m[s[i]] = res.size() - 1;
            }
        }

        return res;
    }
};