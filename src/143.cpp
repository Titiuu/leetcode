#include "head.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> first;
        ListNode *p = head->next;
        while(p){
            first.push_back(p);
            p = p->next;
        }
        p = head;
        while (!first.empty()) {
            p->next = first.back();
            first.pop_back();
            p = p->next;
            if (!first.empty()) {
                p->next = first.front();
                first.pop_front();
                p = p->next;
            }
        }
        p->next = nullptr;
    }
};