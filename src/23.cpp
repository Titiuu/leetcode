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

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](const ListNode *a, const ListNode *b) {
            return a->val > b->val; // 最小堆
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for (auto head: lists)
            if (head) pq.push(head);

        auto dummy = new ListNode(); // 哨兵节点，作为合并后链表头节点的前一个节点
        auto cur = dummy;
        while (!pq.empty()) { // 循环直到堆为空
            auto node = pq.top(); // 剩余节点中的最小节点
            pq.pop();
            if (node->next) // 下一个节点不为空
                pq.push(node->next); // 下一个节点有可能是最小节点，入堆
            cur->next = node; // 合并到新链表中
            cur = cur->next; // 准备合并下一个节点
        }
        return dummy->next; // 哨兵节点的下一个节点就是新链表的头节点
    }
};