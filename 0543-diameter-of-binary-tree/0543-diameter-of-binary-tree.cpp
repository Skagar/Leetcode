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
    //Method-1

    // int height(TreeNode* root)
    // {
    //     if(root==NULL)
    //     return 0;
    //     int lh=height(root->left);
    //     int rh=height(root->right);
    //     return max(lh,rh)+1;
    // }


    //Method 2
    pair<int,int> dofbt(TreeNode*root)
    {
        if(root==NULL)
        {
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int>lpair=dofbt(root->left);
        pair<int,int>rpair=dofbt(root->right);
        int op1=lpair.first;
        int op2=rpair.first;
        int op3=lpair.second+rpair.second;
        pair<int,int>ans;
        ans.first=max(op3,max(op1,op2));
        ans.second=max(lpair.second,rpair.second)+1;
        return ans;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        //Mthod 1

    //    if(root==NULL)
    //    return 0;
    //    int op1=diameterOfBinaryTree(root->left);
    //    int op2=diameterOfBinaryTree(root->right);
    //    int op3=height(root->left)+height(root->right);
    //    int ans=max(op3,max(op1,op2));
    //    return ans;

    //method2
    return dofbt(root).first;
    }
};