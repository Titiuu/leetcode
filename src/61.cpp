#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>
#include <numeric>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)  return head;
        int len = 0, i = 1;
        ListNode *p = head, *tail = nullptr;
        while (p) {
            len++;
            tail = p;
            p = p->next;
        }
        k %= len;
        k = (len - k) % len;
        if (k == 0) return head;  //k等于0直接返回，否则尾连接再截断
        tail->next = head;
        p = head;
        while (p) {
            if (i == k) {
                head = p->next;
                p->next = nullptr;
                break;
            }
            i++;
            p = p->next;
            head = p;
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;
        ListNode* dummy = new ListNode(0), * p = dummy;
        dummy->next = head;
        ListNode* fast = dummy, * slow = dummy;
        int n = 0;
        while (p->next) {
            n++;
            p = p->next;
        }
        if (k % n == 0)
            return dummy->next;
        for (int i = 0; i < k % n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = dummy->next;
        dummy->next = slow->next;
        slow->next = fast->next;
        fast->next = temp;
        return dummy->next;
    }
};