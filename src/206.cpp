#include "head.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head->next == nullptr)
            return head;
        ListNode* last =  reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};