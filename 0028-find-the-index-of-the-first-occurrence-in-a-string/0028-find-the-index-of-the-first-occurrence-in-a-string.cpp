class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.length();
        int l2 = needle.length();
        if (l2 > l1)
            return -1;
        int c = 0;
        int i = c;
        int j = 0;
        while (i < l1 && j < l2) {
            char ch1 = haystack[i];
            char ch2 = needle[j];
            if (ch1 == ch2) {
                i++;
                j++;
            } else {
                i = c++;
                j = 0;
            }
        }
        if(j<l2)
        return -1;
        return (i-j);
    }
};