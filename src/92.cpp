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

class Solution1 {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head->next == nullptr)
            return head;
        ListNode* p = head, * leftPre = nullptr, * rightNext = nullptr;
        int count = 1;
        vector<ListNode*> list;
        while (p) {
            if (count == left - 1)
                leftPre = p;
            else if (count >= left && count <= right) {
                list.push_back(p);
                if (count == right) {
                    if (leftPre == nullptr) {
                        rightNext = p->next;
                        int i = right - left;
                        head = list[i];
                        leftPre = head;
                        i--;
                        while (i > -1) {
                            leftPre->next = list[i];
                            leftPre = leftPre->next;
                            i--;
                        }
                        leftPre->next = rightNext;
                    }
                    else {
                        rightNext = p->next;
                        int i = right - left;
                        while (i > -1) {
                            leftPre->next = list[i];
                            leftPre = leftPre->next;
                            i--;
                        }
                        leftPre->next = rightNext;
                    }
                }
            }
            p = p->next;
            count++;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head->next == nullptr)
            return head;
        ListNode* dummy = new ListNode(), * p = dummy, * leftPre = nullptr, * curr = nullptr, * next = nullptr;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++) {
            p = p->next;
        }
        leftPre = p;
        curr = p->next;
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = leftPre->next;
            leftPre->next = next;
        }
        return dummy->next;
    }
};