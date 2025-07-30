class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int total=0;
        int *prefixmax=new int[n];
        int *suffixmax=new int[n];
        prefixmax[0]=height[0];
        int pmax=INT_MIN;
        pmax=max(height[0],pmax);
        for(int i=1;i<n;i++)
        {
           prefixmax[i]=max(prefixmax[i-1],height[i]);
    
        }
        int smax=INT_MIN;
         suffixmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
          suffixmax[i]=max(suffixmax[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(height[i]<prefixmax[i] && height[i]<suffixmax[i])
            {
                total+=(min(suffixmax[i],prefixmax[i])-height[i]);
            }
        }
return total;
        
    }
};