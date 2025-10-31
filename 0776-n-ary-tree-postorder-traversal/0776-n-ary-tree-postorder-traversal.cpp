/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void postordertraversal(Node* root, vector<int>& post) {
        if (root == NULL)
            return;
        for (int i = 0; i < root->children.size(); i++) {
            postordertraversal(root->children[i], post);
        }
        post.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> post;
        if (root == NULL)
            return post;
        postordertraversal(root, post);
        return post;
    }
};