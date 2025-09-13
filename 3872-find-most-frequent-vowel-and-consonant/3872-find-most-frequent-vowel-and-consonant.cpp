class Solution {
public:
    int maxFreqSum(string s) {
        int ans=0;
        int len=s.length();
        map<char,int>vow;
        map<char,int>cons;
        for(int i=0;i<len;i++)
        {
            char ch=s.at(i);
            if((ch== 'a')||(ch== 'e')||(ch== 'i')||(ch== 'o')||(ch== 'u'))
            {
                vow[ch]++;
            }
            else
            {
                cons[ch]++;
            }
        }
        int vowcount=0;
        int conscount=0;
        int maxi=INT_MIN;
       map<char,int>::iterator it;
       for(it=vow.begin();it!=vow.end();it++)
       {
        maxi=max(maxi,it->second);
       }
       if(maxi!=(INT_MIN))
        vowcount=maxi;
        maxi=INT_MIN;
        for(it=cons.begin();it!=cons.end();it++)
       {
        maxi=max(maxi,it->second);
       }
       if(maxi!=(INT_MIN))
        conscount=maxi;
        ans=vowcount+conscount;
        return ans;
    }
};