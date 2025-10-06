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
    void leftview(TreeNode* root, vector<int>& lv, int level) {
        if (root == NULL)
            return;
        if (level == lv.size())
            lv.push_back(root->val);

        leftview(root->left, lv, level + 1);
        leftview(root->right, lv, level + 1);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        vector<int> lv;
        int level = 0;
        leftview(root, lv, level);
        return lv[lv.size() - 1];
    }
};