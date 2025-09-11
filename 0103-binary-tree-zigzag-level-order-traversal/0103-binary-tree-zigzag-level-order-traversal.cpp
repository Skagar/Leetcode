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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        //Method:1 TC=O(n),SC=O(n);

        /*queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        vector<int>temp;
        int cnt=0;
        while(!q.empty())
        {
            TreeNode* frNode=q.front();
            q.pop();
            if(frNode==NULL)
            {
               if(cnt%2==0)
               {
                ans.push_back(temp);
                temp.clear();
               }
               else
               {
                reverse(temp.begin(),temp.end());
               ans.push_back(temp);
                temp.clear();
               }
               if(!q.empty())
               {
                q.push(NULL);
               }
               cnt++;
            }
            else
            {
                temp.push_back(frNode->val);
                if(frNode->left)
                q.push(frNode->left);
                 if(frNode->right)
                q.push(frNode->right);
                }
        }
        return ans;*/



        queue<TreeNode*>q;
        bool ltor=true; 
        q.push(root);
        vector<vector<int>>ans;
         if(root==NULL)
        return ans;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp(size);
            for(int i=0;i<size;i++)
            {
                TreeNode* frontnode=q.front();
                q.pop();
              int index=ltor?i:size-i-1;
            temp[index]=frontnode->val;
            if(frontnode->left)
            q.push(frontnode->left);
            if(frontnode->right)
            q.push(frontnode->right);
            }
            ans.push_back(temp);
            ltor=!ltor;
        }
        return ans;
    }
};