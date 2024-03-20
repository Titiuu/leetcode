#include "head.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head, * pre = dummy, * next, * p = head;
        while (p != nullptr) {
            for (int i = 0; i < k; i++) {
                p = p->next;
                if (p == nullptr && i != k - 1)
                    return dummy->next;
            }
            for (int i = 0; i < k - 1; i++) {
                next = curr->next;
                ListNode* temp = pre->next;
                pre->next = next;
                curr->next = next->next;
                next->next = temp;
            }
            pre = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head, * pre = dummy, * next, * p = head;
        while (p != nullptr) {
            for (int i = 0; i < k; i++) {
                p = p->next;
                if (p == nullptr && i != k - 1)
                    return dummy->next;
            }
            for (int i = 0; i < k - 1; i++) {
                next = curr->next;
                curr->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = curr;
            curr = curr->next;
        }
        return dummy->next;
    }
};

int main() {
    int a[5] = { 1,2,3,4,5 };
    ListNode* head = new ListNode(0), * p = head;
    for (int i = 0; i < 5; i++) {
        ListNode* node = new ListNode(a[i]);
        p->next = node;
        p = p->next;
    }
    Solution s;
    s.reverseKGroup(head->next, 4);
}