/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Method 1:
        /* if (root == NULL)
             return NULL;
         if (root->val == p->val || root->val == q->val) {
             return root;
         }
         TreeNode* leftans = lowestCommonAncestor(root->left, p, q);
         TreeNode* rightans = lowestCommonAncestor(root->right, p, q);
         if (leftans != NULL && rightans == NULL)
             return leftans;
         if (leftans == NULL && rightans != NULL)
             return rightans;
         if (leftans != NULL && rightans != NULL)
             return root;
         return NULL;*/

        // Method 2:
        if (root == NULL)
            return NULL;

        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
        return NULL;
    }
};