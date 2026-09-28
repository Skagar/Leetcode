class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        stack<char> st;
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')') {
                if (!st.empty()) {
                    maxi = max(maxi, (int)st.size());
                    st.pop();
                }
            }
        }
        if(maxi==INT_MIN)
        return 0;
        return maxi;
    }
};