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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* NewRoot = new TreeNode(val);
            NewRoot->left = root;
            return NewRoot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int cdepth = 1;
        while (!q.empty()) {
            int size = q.size();
            if (cdepth++ == (depth - 1)) {
                for (int i = 0; i < size; i++) {
                    TreeNode* fnode = q.front();
                    q.pop();
                    TreeNode* newnode1 = new TreeNode(val);
                    TreeNode* newnode2 = new TreeNode(val);
                    newnode1->left = fnode->left;
                    fnode->left = newnode1;
                    newnode2->right = fnode->right;
                    fnode->right = newnode2;
                }
            } else {
                for (int i = 0; i < size; i++) {
                    TreeNode* fnode = q.front();
                    q.pop();
                    if (fnode->left)
                        q.push(fnode->left);
                    if (fnode->right)
                        q.push(fnode->right);
                }
            }
        }
        return root;
    }
};