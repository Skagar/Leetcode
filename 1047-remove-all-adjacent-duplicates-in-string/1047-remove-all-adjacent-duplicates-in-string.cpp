class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int len = s.length();
        string g = "";
        for (int i = 0; i < len; i++) {
            char ch = s.at(i);
            bool flag = false;
            while (!st.empty() && st.top() == ch) {
                st.pop();
                flag = true;
            }
            if (flag == false) {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            g.push_back(st.top());
            st.pop();
        }
        reverse(g.begin(), g.end());
        return g;
    }
};