#include "head.h"

//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* L) {
        ListNode node, * head = &node, * p = head;
        head->next = L;
        while (p->next && p->next->next) {
            ListNode* temp = p->next;
            p->next = temp->next;
            temp->next = temp->next->next;
            p->next->next = temp;
            p = temp;
        }
        return head->next;
    }
};