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
    int calmaxamt(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if (root == NULL)
            return 0;
        if (mp.find(root) != mp.end())
            return mp[root];
        int tk = root->val;
        int ntk = 0;
        if (root->left != NULL)
            tk += calmaxamt(root->left->left, mp) +
                  calmaxamt(root->left->right, mp);
        if (root->right != NULL)
            tk += calmaxamt(root->right->left, mp) +
                  calmaxamt(root->right->right, mp);
        ntk += calmaxamt(root->left, mp) + calmaxamt(root->right, mp);
        return mp[root] = max(tk, ntk);
    }

public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        return calmaxamt(root, mp);
    }
};