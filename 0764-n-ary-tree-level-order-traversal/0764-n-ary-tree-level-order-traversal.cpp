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
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        vector<int> temp;
        while (!q.empty()) {
            Node* frontnode = q.front();
            q.pop();
            if (frontnode == NULL) {
                ans.push_back(temp);
                temp.clear();
                if (!q.empty())
                    q.push(NULL);
            } else {
                temp.push_back(frontnode->val);
                int size = frontnode->children.size();
                for (int i = 0; i < size; i++) {
                    q.push(frontnode->children[i]);
                }
            }
        }
        return ans;
    }
};