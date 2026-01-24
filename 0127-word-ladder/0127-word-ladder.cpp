class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> q;
        set<string> st(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        st.erase(beginWord);
        int n = wordList[0].length();
        while (!q.empty()) {
            string s = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if (s == endWord)
                return lvl;
            for (int i = 0; i < n; i++) {
                char first = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if (st.find(s) != st.end()) {
                        q.push({s, lvl + 1});
                        st.erase(s);
                    }
                }
                s[i] = first;
            }
        }
        return 0;
    }
};