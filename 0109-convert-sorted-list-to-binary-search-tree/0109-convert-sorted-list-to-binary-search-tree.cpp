/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* createBST(TreeNode* root, vector<int>& inorder, int s, int e) {
        if (s > e)
            return NULL;
        int m = s + (e - s) / 2;
        int ele = inorder[m];
        root = new TreeNode(ele);
        root->left = createBST(root->left, inorder, s, m - 1);
        root->right = createBST(root->right, inorder, m + 1, e);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        vector<int> inorder;
        ListNode* temp = head;
        while (temp != NULL) {
            inorder.push_back(temp->val);
            temp = temp->next;
        }
        TreeNode* root = NULL;
        int n = inorder.size();
        return createBST(root, inorder, 0, n - 1);
    }
};