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

