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
        ListNode *p = head, *prenode = nullptr;
        if (p == nullptr) return head;
        while(p->next) {
            if (p->val == p->next->val) {
                if (prenode == nullptr) {
                    p = p->next;
                    head = p;
                }
                else {
                    prenode->next = p->next;
                    p = p->next;
                }
            }
            else {
                prenode = p;
                p = p->next;
            }
        }
        return head;
    }
};