/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    void countgoodnodes(TreeNode* root, int& cnt, int maxval) {
        if (root == NULL)
            return;
        maxval = max(maxval, root->val);
        if (root->val >= maxval)
            cnt++;
        countgoodnodes(root->left, cnt, maxval);
        countgoodnodes(root->right, cnt, maxval);
    }

public:
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxval = root->val;
        countgoodnodes(root, cnt, maxval);
        return cnt;
    }
};