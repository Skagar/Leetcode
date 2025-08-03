#include<bits/stdc++.h>
class Solution {
public:
    vector<int> findpse(vector<int> heights)
    {
        
        stack<int>st;
         int n=heights.size();
         vector<int>ans;
            for(int i=0;i<n;i++)
            {
               while(!st.empty() && (heights[i]<heights[st.top()]))
               {
                st.pop();
               }
               if(st.empty())
                ans.push_back(-1);
                else
              ans.push_back(st.top());
               st.push(i);
            }
            return ans;
        
        return ans;
    }
     vector<int> findnse(vector<int> heights)
    {
        int n=heights.size();
        vector<int>ans;
        stack<int>st;
            for(int i=n-1;i>=0;i--)
            {
               while(!st.empty() && (heights[st.top()]>=heights[i]))
               {
                st.pop();
               }
               if(st.empty())
              ans.push_back(n);
              else
              ans.push_back(st.top());
               st.push(i);
            }
            reverse(ans.begin(),ans.end());
        
            return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>pse=findpse(heights);
        vector<int>nse=findnse(heights);
         int n=heights.size();
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
           int len=heights[i];
          int bred= nse[i]-pse[i]-1;
          int newArea= len*bred;
          area=max(area,newArea);
        }
        return area;
    }
};