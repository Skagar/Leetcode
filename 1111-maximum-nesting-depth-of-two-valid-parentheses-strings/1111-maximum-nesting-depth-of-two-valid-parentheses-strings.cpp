class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int len = seq.length();
        vector<int> arr(len);
        int da = 0;
        int db = 0;
        string a = "";
        string b = "";
        for (int i = 0; i < len; i++) {
            char ch = seq[i];
            if (ch == '(') {
                if (da < db) {
                    arr[i] = 0;
                    a += ch;
                    da++;
                } else if (da > db) {
                    arr[i] = 1;
                    b += ch;
                    db++;
                } else {
                    arr[i] = 0;
                    a += ch;
                    da++;
                }
            } else if (ch == ')') {
                if (da > db) {
                    arr[i] = 0;
                    a += ch;
                    da--;
                } else if (da < db) {
                    arr[i] = 1;
                    b += ch;
                    db--;
                } else {
                    arr[i] = 0;
                    a += ch;
                    da--;
                }
            }
        }
        return arr;
    }
};