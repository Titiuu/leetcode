#include "head.h"


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            Node* ret = new Node(insertVal);
            ret->next = ret;
            return ret;
        }
        Node* p = head;
        while (p->next != head) {
            if ((p->val <= insertVal && p->next->val >= insertVal)
                || (p->val <= insertVal && p->next->val <= insertVal && p->val >= p->next->val)
                || (p->val >= insertVal && p->next->val >= insertVal && p->val >= p->next->val)) {
                Node* next = new Node(insertVal);
                Node* t = p->next;
                p->next = next;
                next->next = t;
                return head;
            }
            p = p->next;
        }
        Node* next = new Node(insertVal);
        Node* t = p->next;
        p->next = next;
        next->next = t;
        return head;
    }
};

int main() {
    Solution S;
    S.insert(nullptr, 1);
    return 0;
}