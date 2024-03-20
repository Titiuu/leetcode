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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head, *prenode = nullptr;
        while (p)
        {
            if (p->next == nullptr)  return head;
            if (p->val != p->next->val) {
                prenode = p;
                p = p->next;
                if (p->next == nullptr) return head;
            }
            else {
                int val = p->val;
                while (p->val == val) {
                    p = p->next;
                    if (!p) {
                        if (prenode)
                            prenode->next = nullptr;
                        else
                            head = p;
                        return head;
                    }
                }
                if (prenode)
                    prenode->next = p;
                else
                    head = p;
            }
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0), * pre = dummy, * p = head;
        dummy->next = head;
        while (p && p->next) {
            if (p->val == p->next->val) { // 说明需要删除节点
                int value = p->val;
                while (p!=nullptr && p->val == value) {
                    p = p->next;
                }
                pre->next = p;
            }
            else { // 不需要删除则说明为孤立节点，更新pre，并使得p指向下一个位置
                pre = p;
                p = p->next;
            }
        }
        return dummy->next;
    }
};