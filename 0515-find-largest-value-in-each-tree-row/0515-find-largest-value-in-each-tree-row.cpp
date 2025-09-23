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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        vector<int> ans;
        if (root == NULL)
            return ans;
        while (!q.empty()) {
            TreeNode* frontnode = q.front();
            q.pop();
            if (frontnode == NULL) {
                ans.push_back(*max_element(temp.begin(), temp.end()));
                temp.clear();
                if (!q.empty())
                    q.push(NULL);
            } else {
                temp.push_back(frontnode->val);
                if (frontnode->left)
                    q.push(frontnode->left);
                if (frontnode->right)
                    q.push(frontnode->right);
            }
        }
        return ans;
    }
};