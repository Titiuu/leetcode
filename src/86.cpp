#include "head.h"

class Solution { //不保留初始相对位置，一次遍历
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummy = new ListNode(0), * p = head->next, * tail = head;
        dummy->next = head;
        while (p) {
            if (p->val < x) {
                ListNode* temp = dummy->next, * next = p->next;
                dummy->next = p;
                p->next = temp;
                p = next;
            }
            else {
                tail->next = p;
                tail = p;
                p = p->next;
            }
        }
        tail->next = nullptr;
        return dummy->next;
    }
};

class Solution { //保留初始相对位置，维护两个链表
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next == nullptr || x <= -100 || x >= 100)
            return head;
        ListNode* dummySmall = new ListNode(0), * dummyBig = new ListNode(0), *p = head, * tail1 = dummySmall, * tail2 = dummyBig;
        while (p) {
            if (p->val < x) {
                tail1->next = p;
                tail1 = p;
                p = p->next;
            }
            else {
                tail2->next = p;
                tail2 = p;
                p = p->next;
            }
        }
        tail1->next = dummyBig->next;
        tail2->next = nullptr;
        return dummySmall->next;
    }
};