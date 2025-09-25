/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void inordertraversal(TreeNode*root,vector<int>&in)
    {
        if(root==NULL)
        return;
        inordertraversal(root->left,in);
        in.push_back(root->val);
        inordertraversal(root->right,in);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int>in;
        inordertraversal(root,in);
        if(k-1 < in.size())
        return in[k-1];
        return -1;
    }
};