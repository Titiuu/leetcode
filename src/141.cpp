#include "head.h"

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head)
            return false;
        ListNode* fast = head, * slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};