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
    void pre(Node *root, vector<int>&nodes)
    {
        if(root == NULL)
            return;

        nodes.push_back(root->val);
        for(int i = 0; i<root->children.size(); i++)
            pre((root->children)[i], nodes);
    }

    vector<int> preorder(Node* root) {
        vector<int>nodes;
        pre(root, nodes);
        return nodes;
    }
};