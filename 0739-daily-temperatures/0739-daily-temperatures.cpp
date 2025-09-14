class Solution {
    private:
    //used concept of NEXT GREATER ELEMENT to find indexes of next higher temperatures
    void findngeindex(vector<int>& temperatures,vector<int>&nge)
    {
        stack<int>st;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && (temperatures[i]>=temperatures[st.top()]))
            {
             st.pop();
            }
            if(st.empty())
           nge.push_back(-1);
            else
            nge.push_back(st.top());
            st.push(i);
        }
        reverse(nge.begin(),nge.end());
    }
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        vector<int>nge;
        findngeindex(temperatures,nge);
        int n=temperatures.size();
        for(int i=0;i<n;i++)
        {
            if( nge[i] != (-1))
            ans.push_back(nge[i]-i);
            else
            ans.push_back(0);
        }
        return ans;
    }
};