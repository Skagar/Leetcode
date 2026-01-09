class Solution {
public:
    int maxDistinct(string s) {
        int len=s.length();
        set<char>st;
        for(int i=0;i<len;i++)
        {
            st.insert(s.at(i));
        }
        if(!st.empty())
        return st.size();

        return 0;
    }
};