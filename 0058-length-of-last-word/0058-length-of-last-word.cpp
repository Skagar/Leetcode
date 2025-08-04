class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=s.length();
        int index;
        for(int i=len-1;i>=0;i--)
        {
            if(s.at(i)==' ')
            continue;
            else
            {
                index=i;
                break;
            }
        }
        int cnt=0;
        while((index>=0 && index<len) && s.at(index)!=' ')
        {
            cnt++;
            index--;
        }
        return cnt;
    }
};