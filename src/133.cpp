#include "head.h"

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<int, Node*> mp;
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;
        if (mp.count(node->val) > 0)
            return mp[node->val];
        Node* first = new Node(node->val);
        mp[node->val] = first;
        for (auto x : node->neighbors) {
            first->neighbors.push_back(cloneGraph(x));
        }
        return first;
    }
};