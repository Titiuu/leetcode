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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode node, * head = &node, * pa = a, * pb = b, * tail;
        if (pa->val < pb->val) {
            head->next = pa;
            tail = pa;
            pa = pa->next;
        }
        else {
            head->next = pb;
            tail = pb;
            pb = pb->next;
        }
        while (pa && pb) {
            if (pa->val < pb->val) {
                tail->next = pa;
                tail = tail->next;
                pa = pa->next;
            }
            else {
                tail->next = pb;
                tail = tail->next;
                pb = pb->next;      
            }
        }
        if (pa)
            tail->next = pa;
        else
            tail->next = pb;
        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0)    return nullptr;
        while (k > 1) {
            for (int i = 0; i < k / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k / 2]);
            }
            int t = k;
            k /= 2;
            if (t & 1 == 1) {
                lists[t / 2] = lists[t - 1];
                k++;
            }
        }
        return lists[0];
    }
};