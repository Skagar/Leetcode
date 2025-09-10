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
     
       // Method -1
    // int calheight(TreeNode*root,bool &flag)
    // {
    //     if(root==NULL)
    //     return 0;
    //     int leftheight=calheight(root->left,flag);
    //     int rightheight=calheight(root->right,flag);
    //     int diff=rightheight-leftheight;
    //     if(abs(diff)>1)
    //     flag=false;
    //     return  (max(leftheight,rightheight)+1);
    // }


    //Method 2
    int height(TreeNode* root)
    {
        if(root==NULL)
        return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return max(lh,rh)+1;
    }
public:
    bool isBalanced(TreeNode* root) {
        //Method 1

        // bool flag=true;
        // int total=calheight(root,flag);
        // return flag;

        //Method 2
     if(root==NULL)
     return true;

        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        bool diff = abs(height(root->left)-height(root->right))<=1;
        if(left&&right&&diff)
        return true;
        else 
        return false;
    }
};