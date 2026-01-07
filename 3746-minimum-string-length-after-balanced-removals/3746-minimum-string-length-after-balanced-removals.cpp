class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> st;
        int l = s.length();
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            char ch = s.at(i);
            if (st.empty())
                st.push(ch);
            else {
                if (st.top() == ch)
                    st.push(ch);
                else
                    st.pop();
            }
        }
        return st.size();
    }
};