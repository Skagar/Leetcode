class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        for (int i = 0; i < n; i++) {
            char ch = letters[i];
            if ((int)ch > (int)target)
                return ch;
        }
        return letters[0];
    }
};