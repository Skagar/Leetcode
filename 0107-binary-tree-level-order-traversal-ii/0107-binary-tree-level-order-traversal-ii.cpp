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
    void createmapping(TreeNode* root, unordered_map<int, vector<int>>& mp,
                       int level) {
        if (root == NULL)
            return;
        mp[level].push_back(root->val);
        createmapping(root->left, mp, level + 1);
        createmapping(root->right, mp, level + 1);
    }

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        unordered_map<int, vector<int>> mp;
        int level = 0;
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        createmapping(root, mp, level);
         int maxLevel = 0;
        for (auto& pair : mp) {
            maxLevel = max(maxLevel, pair.first);
        }
        
        // Add levels from bottom to top
        for (int i = maxLevel; i >= 0; i--) {
            ans.push_back(mp[i]);
        }
        
        return ans;
    }
};