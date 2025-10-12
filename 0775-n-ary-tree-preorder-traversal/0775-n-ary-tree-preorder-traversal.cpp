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
    void generatepreorder(Node *root,vector<int>&pre)
    {
        if(root==NULL)
        return;
        pre.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
        {
            generatepreorder(root->children[i],pre);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int>pre;
        if(root==NULL)
        return pre;
        generatepreorder(root,pre);
        return pre;
    }
};