#include "head.h"

class MyCircularQueue {
private:
    vector<int> que;
    int len;
    int f, b;
    bool ept;
public:
    MyCircularQueue(int k) {
        ept = true;
        len = k;
        f = b = 0;
        que.resize(k);
    }
    
    bool enQueue(int value) {
        if (f == b && !ept)
            return false;
        que[b] = value;
        b = (b + 1) % len;
        ept = false;
        return true;
    }
    
    bool deQueue() {
        if (ept)
            return false;
        f = (f + 1) % len;
        if (f == b)
            ept = true;
        else
            ept = false;
        return true;
    }
    
    int Front() {
        if (ept)
            return -1;
        return que[f];
    }
    
    int Rear() {
        if (ept)
            return -1;
        return que[b - 1 >= 0 ? b - 1 : b + len - 1];
    }
    
    bool isEmpty() {
        return ept;
    }
    
    bool isFull() {
        return (!ept) && f == b;
    }
};

int main() {
    MyCircularQueue* c = new MyCircularQueue(3);
    cout << c->enQueue(1);
    cout << c->enQueue(2);
    cout << c->enQueue(3);
    cout << c->enQueue(4);
    cout << c->Rear();
    cout << c->isFull();
    cout << c->deQueue();
    cout << c->enQueue(4);
    cout << c->Rear();
    return 0;
}