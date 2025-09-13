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
    void levelordertraversal(TreeNode* root, vector<int>&ans)
    {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<int>temp;
        while(!q.empty())
        {
            
            TreeNode* frontnode=q.front();
            q.pop();
            if(frontnode == NULL)
            {
                ans.push_back(temp[temp.size()-1]);
                temp.clear();
                if(!q.empty())
                q.push(NULL);
            }
            else
            {
                temp.push_back(frontnode->val);
                if(frontnode->left)
                q.push(frontnode->left);
                if(frontnode->right)
                q.push(frontnode->right);
            }
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
        return ans;
        levelordertraversal(root,ans);
        return ans;
    }
};