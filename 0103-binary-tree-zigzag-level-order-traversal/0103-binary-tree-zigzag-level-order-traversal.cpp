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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        bool ltor = true;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode* fn = q.front();
                temp.push_back(fn->val);
                q.pop();
                if (fn->left)
                    q.push(fn->left);
                if (fn->right)
                    q.push(fn->right);
            }
            if (ltor) {
                ans.push_back(temp);
                temp.clear();
                ltor = !ltor;
            } else {
                reverse(temp.begin(), temp.end());
                ans.push_back(temp);
                temp.clear();
                ltor = !ltor;
            }
        }
        return ans;
    }
};