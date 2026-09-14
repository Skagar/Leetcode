class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int fx1 = rec1[0];
        int fy1 = rec1[1];
        int fx2 = rec1[2];
        int fy2 = rec1[3];
        int sx1 = rec2[0];
        int sy1 = rec2[1];
        int sx2 = rec2[2];
        int sy2 = rec2[3];
        if ((sx1 < fx2 && sy1 < fy2) && (sx2 > fx1 && sy2 > fy1))
            return true;
        return false;
    }
};