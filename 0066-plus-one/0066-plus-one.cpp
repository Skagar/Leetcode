class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        reverse(digits.begin(),digits.end());
        int carry=(digits[0]+1)/10;
        int sum=(digits[0]+1)%10;
        digits[0]=sum;
        for(int i=1;i<n;i++)
        {
             int c=(digits[i]+carry)/10;
            digits[i]=(digits[i]+carry)%10;
            carry=c;
        }
        if(carry!=0)
        digits.push_back(carry);
        reverse(digits.begin(),digits.end());
        return digits;
    }
};