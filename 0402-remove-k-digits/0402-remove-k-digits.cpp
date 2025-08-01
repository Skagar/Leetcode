class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        string ans="";
        int n=num.length();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && k>0 && ((st.top()-'0')>(num[i]-'0')))
            {
                st.pop();
                k--;
            }
             st.push(num[i]);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        while(!st.empty())
        {
            char ch=st.top();
            ans+=ch;
            st.pop();
        }
         while(ans.length()!=0 && ans.back()=='0')
         {
            ans.pop_back();
         }
         int m=ans.length();
         for(int i=0;i<m/2;i++)
         {
            swap(ans[i],ans[m-i-1]);
         }
         if(ans.empty())
         return "0";
        return ans;
    }
};