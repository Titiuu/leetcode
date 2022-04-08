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
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(Node* root) {
        if (!root)
            return res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            int cnt = q.size();
            for (int i = 0; i < cnt; i++) {
                Node* front = q.front();
                level.emplace_back(front->val);
                for (auto& x : front->children) {
                    q.push(x);
                }
                q.pop();
            }
            res.push_back(level);
        }
        return res;
    }
};