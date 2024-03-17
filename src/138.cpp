#include "head.h"

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> node2node;
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        if (!p)
            return p;
        Node* newHead = new Node(p->val);
        Node* pre = newHead;
        node2node[head] = newHead;
        p = p->next;
        while (p) {
            Node* newNode = new Node(p->val);
            node2node[p] = newNode;
            pre->next = newNode;
            pre = newNode;
            p = p->next;
        }
        p = head;
        Node* ptr = newHead;
        while (p) {
            if (p->random)
                ptr->random = node2node[p->random];
            p = p->next;
            ptr = ptr->next;
        }
        return newHead;
    }
};