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
    TreeNode *createtree(TreeNode*root,int s,int e,vector<int>&nums)
    {
        if(s>e)
        return NULL;
        int mid=s+(e-s)/2;
        root=new TreeNode(nums[mid]);
        root->left=createtree(root->left,s,mid-1,nums);
        root->right=createtree(root->right,mid+1,e,nums);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root=NULL;
        int s=0;
        int e=nums.size()-1;
       return  createtree(root,s,e,nums);
    }
};