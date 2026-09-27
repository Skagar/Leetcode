class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] != ')')
                st.push(s[i]);
            else {
                string temp = "";
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                if (st.top() == '(')
                    st.pop();
                for (int j = 0; j < temp.length(); j++) {
                    st.push(temp[j]);
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};