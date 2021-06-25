/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <stdio.h>
#include <iostream>
#include <vector>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode;
        ListNode* p = head;        
        int carry = 0;
        while(l1||l2) {
            ListNode* newnode=new ListNode(0);
            int temp = 0;
            if(l1) {
                newnode->val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                newnode->val += l2->val;
                l2 = l2->next;
            }
            newnode->val += carry;
            temp += newnode->val / 10;
            carry = temp;
            newnode->val %= 10;
            p->next = newnode;
            p=p->next;
        }
            if (carry != 0) {
            ListNode* newnode = new ListNode(1);
            p->next = newnode;
        }
        return head->next;
    }
};

int main(){
    ListNode n1(2),n2(4),n3(3),n4(5),n5(6),n6(4);
    n1.next=&n2;
    n2.next=&n3;
    n4.next=&n5;
    n5.next=&n6;
    ListNode* l1=&n1, *l2=&n4;
    Solution a;
    ListNode* result = a.addTwoNumbers(l1,l2);
    cout<<result->val<<result->next->val<<result->next->next->val;
}