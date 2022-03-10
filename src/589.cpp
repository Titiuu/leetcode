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
    vector<int> pre;
public:
    vector<int> preorder(Node* root) {
        if (root != nullptr) {
            pre.emplace_back(root->val);
            for (auto& x : root->children) {
                preorder(x);
            }
        }
        return pre;
    }
};