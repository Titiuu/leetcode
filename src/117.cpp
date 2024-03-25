#include "head.h"

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                Node* first = q.front();
                q.pop();
                if (i != len - 1) {
                    Node* second = q.front();
                    first->next = second;
                }
                else
                    first->next = nullptr;
                if (first->left)
                    q.push(first->left);
                if (first->right)
                    q.push(first->right);
            }
        }
        return root;
    }
};