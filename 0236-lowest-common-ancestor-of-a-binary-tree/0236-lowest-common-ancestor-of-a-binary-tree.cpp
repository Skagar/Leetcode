/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    // Finding node path for TreeNode*p
    void LCApnode(TreeNode* root, TreeNode* p, TreeNode* q,
                  vector<int>& pnode) {
        if (!pnode.empty() && pnode.back() == p->val)
            return;
        if (root == NULL)
            return;
        pnode.push_back(root->val);
        LCApnode(root->left, p, q, pnode);
        if (!pnode.empty() && pnode.back() == p->val)
            return;
        LCApnode(root->right, p, q, pnode);
        if (!pnode.empty() && pnode.back() == p->val)
            return;
        else
            pnode.pop_back();
    }
    // Finding node path for TreeNode*q
    void LCAqnode(TreeNode* root, TreeNode* p, TreeNode* q,
                  vector<int>& qnode) {
        if (!qnode.empty() && qnode.back() == q->val)
            return;
        if (root == NULL)
            return;
        qnode.push_back(root->val);
        LCAqnode(root->left, p, q, qnode);
        if (!qnode.empty() && qnode.back() == q->val)
            return;
        LCAqnode(root->right, p, q, qnode);
        if (!qnode.empty() && qnode.back() == q->val)
            return;
        else
            qnode.pop_back();
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<int> pnode;
        vector<int> qnode;
        LCApnode(root, p, q, pnode);
        LCAqnode(root, p, q, qnode);
        int i = pnode.size() - 1;
        int j = qnode.size() - 1;
      
        // Traversing backwards for each path and first common Node is returned
        if (i < j) {
            while ((i >= 0) && (j >= 0) && (j != i)) {
                j--;
            }
        } else if (i > j) {
            while ((i >= 0) && (j >= 0) && (i != j)) {
                i--;
            }
        } 
            while ((i >= 0) && (j >= 0) && (pnode[i] != qnode[j])) {
                i--;
                j--;
            }
        TreeNode* temp = new TreeNode(pnode[i]);
        return temp;
    }
};