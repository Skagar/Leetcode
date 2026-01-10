class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int maxi = INT_MIN;
        for (int i = 0; i < s.length(); i++) {
            char ch = s.at(i);
            if (ch == '(')
                st.push(ch);
            else {
                if ((!st.empty()) && (st.top() == '(') && (ch == ')')) {
                    int size = st.size();
                    if (size > maxi)
                        maxi = size;
                    st.pop();
                }
            }
        }
        if(maxi!=INT_MIN)
        return maxi;
        return 0;
    }
};