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
   void createmapping( map<int,int>&mp,vector<int>& inorder)
    {
        int n=inorder.size();
        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }
    }
    
    TreeNode *create(vector<int>& preorder,vector<int>& inorder,map<int,int>&mp,int n,int &index,int startindex,int endindex, TreeNode *root)
    {
        if(index>=n || startindex>endindex)
        return NULL;
        int ele=preorder[index++];
        TreeNode *temp=new TreeNode(ele);
        if(root==NULL)
        root=temp;
        int pos=mp[ele];
         root->left=create(preorder,inorder,mp,n,index,startindex,pos-1,root->left);
         root->right=create(preorder,inorder,mp,n,index,pos+1,endindex,root->right);
         return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int preindex=0;
        TreeNode* root=NULL;
        int n=preorder.size();
        createmapping(mp,inorder);
      root= create(preorder,inorder,mp,n,preindex,0,n-1,root);
       return root;
    }
};