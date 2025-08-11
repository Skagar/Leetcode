class Solution {
public:
  void generateparen(vector<string>&temp,int n,string &arr)
  {
      if(arr.length()==(2*n))
      {
        temp.push_back(arr);
        return;
      }
      arr.push_back('(');
      generateparen(temp,n,arr);
      arr.pop_back();
        arr.push_back(')');
      generateparen(temp,n,arr);
      arr.pop_back();
  }
 bool validparenthesis(string s)
 {
    int n=s.length();
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        char ch=s.at(i);
        if(ch=='(')
        st.push(ch);
        else
        {
            if(!st.empty())
            {
                char ch1=st.top();
           if((ch1=='(') && (ch==')'))
           st.pop();
           else
           return false;
            }
            else
           return false;
        }
    }
    if(st.empty())
    return true;
    else
    return false;
 }
    vector<string> generateParenthesis(int n) {
        vector<string>temp;
        string arr="";
         generateparen(temp,n,arr);
         vector<string>ans;
         for(int i=0;i<temp.size();i++)
         {
            string s=temp[i];
            if(validparenthesis(s)==true)
            ans.push_back(s);
         }
         return ans;
    }
};