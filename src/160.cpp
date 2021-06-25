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
#include <unordered_map>
#include <set>

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
    int getLength(ListNode* head) {
        int ans = 0;
        for (;head;head = head->next) ++ans;
        return ans;
    }

    ListNode *getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lenA = getLength(headA);
        int lenB = getLength(headB);
        int len = 0;
        if (lenA > lenB) {
            len = lenB;
            while (lenA-- > lenB)
                headA = headA->next;
        } else {
            len = lenA;
            while (lenB-- > lenA)
                headB = headB->next;
        }
        while (len--) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};