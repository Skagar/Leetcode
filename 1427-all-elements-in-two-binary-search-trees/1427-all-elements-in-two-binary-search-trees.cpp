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
    void inordertraversal(TreeNode* root, vector<int>& inorder) {
        if (root == NULL)
            return;
        inordertraversal(root->left, inorder);
        inorder.push_back(root->val);
        inordertraversal(root->right, inorder);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> inorder1;
        vector<int> inorder2;
        int i = 0;
        int j = 0;
        inordertraversal(root1, inorder1);
        inordertraversal(root2, inorder2);
        int n1 = inorder1.size();
        int n2 = inorder2.size();
        while (i < n1 && j < n2) {
            if (inorder1[i] < inorder2[j]) {
                ans.push_back(inorder1[i]);
                i++;
            } else if (inorder1[i] > inorder2[j]) {
                ans.push_back(inorder2[j]);
                j++;
            } else {
                ans.push_back(inorder2[j]);
                ans.push_back(inorder2[j]);
                j++;
                i++;
            }
        }
        while (i < n1) {
            ans.push_back(inorder1[i]);
            i++;
        }
        while (j < n2) {
            ans.push_back(inorder2[j]);
            j++;
        }
        return ans;
    }
};