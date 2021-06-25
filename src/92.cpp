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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)  return head;
        ListNode *p = head, *prenode, *firstnode, *lastnode, *nextnode;
        int i = 1;
        if (left == 1) {
            while (p != nullptr)
            {
                lastnode = p;
                p = p->next;
                i++;
                while (i != right)
                {
                    nextnode = p->next;
                    p->next = lastnode;
                    lastnode = p;
                    p = nextnode;
                    i++;
                }
                nextnode = p->next;
                p->next = lastnode;
                head->next = nextnode;
                head = p;
                p = nullptr;
            }
            return head;
        }
        
        while (p != nullptr) {
            if (i == left - 1) {
                prenode = p;
                p = p->next;
                i++;
            }
            else {
                p = p->next;
                i++;
                continue;
            }
            firstnode = p;
            lastnode = p;
            p = p->next;
            i++;
            while (i != right) {
                nextnode = p->next;
                p->next = lastnode;
                lastnode = p;
                p = nextnode;
                i++;
            }
            nextnode = p->next;
            prenode->next = p;
            p->next = lastnode;
            firstnode->next = nextnode;
            p = nullptr;
        }
        return head;
    }
};