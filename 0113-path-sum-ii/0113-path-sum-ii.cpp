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
private:
    void findpath(TreeNode* root, vector<vector<int>>& ans, vector<int> temp,
                  int targetsum) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL) {
            int sum = 0;
            temp.push_back(root->val);
            sum = accumulate(temp.begin(), temp.end(), 0);
            if (sum == targetsum)
                ans.push_back(temp);
            return;
        }
        temp.push_back(root->val);
        findpath(root->left, ans, temp, targetsum);
        findpath(root->right, ans, temp, targetsum);
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        vector<int> temp;
        findpath(root, ans, temp, targetSum);
        return ans;
    }
};