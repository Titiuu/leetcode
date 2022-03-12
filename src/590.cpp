#include "head.h"


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


class Solution {
private:
    void dfs(Node* root, vector<int> &temp) {
        if (root == nullptr)
            return;
        for (auto& x : root->children) {
            dfs(x, temp);
        }
        temp.push_back(root->val);
    }
public:

    vector<int> postorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};