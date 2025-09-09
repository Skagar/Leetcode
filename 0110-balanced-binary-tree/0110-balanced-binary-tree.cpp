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
    int calheight(TreeNode*root,bool &flag)
    {
        if(root==NULL)
        return 0;
        int leftheight=calheight(root->left,flag);
        int rightheight=calheight(root->right,flag);
        int diff=rightheight-leftheight;
        if(abs(diff)>1)
        flag=false;
        return  (max(leftheight,rightheight)+1);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        int total=calheight(root,flag);
        return flag;
    }
};