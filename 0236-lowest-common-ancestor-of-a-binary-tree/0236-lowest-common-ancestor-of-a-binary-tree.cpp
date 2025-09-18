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
    // METHOD 1:

    // Finding node path for TreeNode*p

    /* void LCApnode(TreeNode* root, TreeNode* p, TreeNode* q,
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
     }*/
    // Finding node path for TreeNode*q
    /*void LCAqnode(TreeNode* root, TreeNode* p, TreeNode* q,
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
    }*/
//Method 2:
    TreeNode* LCA(TreeNode* root, int n1, int n2) {
        if (root == NULL)
            return NULL;
        if (root->val == n1 || root->val == n2)
            return root;
        TreeNode* leftans = LCA(root->left, n1, n2);
        TreeNode* rightans = LCA(root->right, n1, n2);
        if (leftans != NULL && rightans != NULL)
            return root;
        else if (leftans == NULL && rightans != NULL)
            return rightans;
        else if (leftans != NULL && rightans == NULL)
            return leftans;
        else
            return NULL;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /* vector<int> pnode;
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
         return temp;*/

        int n1 = p->val;
        int n2 = q->val;
        TreeNode* temp = LCA(root, n1, n2);
        return temp;
    }
};