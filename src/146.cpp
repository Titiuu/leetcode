#include "head.h"

struct DuaListNode {
    int key;
    int value;
    DuaListNode* pre;
    DuaListNode* next;
    DuaListNode() : key(0), value(0), pre(nullptr), next(nullptr) {}
    DuaListNode(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, DuaListNode*> mp;
    DuaListNode* head, * tail;

    LRUCache(int cap) {
        capacity = cap;
        head = new DuaListNode();
        tail = new DuaListNode();
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (mp.count(key)) { // 断开，从头节点插入
            DuaListNode* curr = mp[key];
            curr->pre->next = curr->next;
            curr->next->pre = curr->pre;

            curr->next = head->next;
            head->next->pre = curr;
            head->next = curr;
            curr->pre = head;
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) { // 存在，更新值，移到最前
            DuaListNode* curr = mp[key];
            curr->pre->next = curr->next;
            curr->next->pre = curr->pre;

            curr->next = head->next;
            head->next->pre = curr;
            head->next = curr;
            curr->pre = head;

            curr->value = value;
        }
        else { // 不存在，创建新的结点，然后插入到头部；判断是否超出容量，超出的话删除尾部结点，并基于key删除map中k-v
            DuaListNode* newNode = new DuaListNode(key, value);
            newNode->next = head->next;
            head->next->pre = newNode;
            head->next = newNode;
            newNode->pre = head;
            if (mp.size() == capacity) {
                DuaListNode* toDel = tail->pre;
                tail->pre = toDel->pre;
                toDel->pre->next = tail;
                mp.erase(toDel->key);
                delete toDel;
                mp[key] = newNode;
            }
            else
                mp[key] = newNode;
        }
    }
};
