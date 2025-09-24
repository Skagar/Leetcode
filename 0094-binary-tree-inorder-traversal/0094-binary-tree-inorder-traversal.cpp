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
public:
    // Method 1: Using Recursion

    /*void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }*/

    // Method 2: Using Morris Order Traversal

    void morrisorder(TreeNode* root, vector<int>& in) {
        TreeNode* cur = root;
        while (cur != NULL) {
            if (cur->left == NULL) {
                in.push_back(cur->val);
                cur = cur->right;
            } else {
                TreeNode* pred = cur->left;
                while (pred->right != NULL && pred->right != cur) {
                    pred = pred->right;
                }
                if (pred->right == NULL) {
                    pred->right = cur;
                    cur = cur->left;
                } else {
                    pred->right = NULL;
                    in.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {

        // vector<int>ans;
        //  inorder(root,ans);
        //  return ans;

        vector<int> in;
        morrisorder(root, in);
        return in;
    }
};