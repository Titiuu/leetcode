#include "head.h"

class MyCalendarThree {
    map<int,int> pool;
public:
    MyCalendarThree() {}
    
    int book(int start, int end) {
        pool[start]+=1;
        pool[end]-=1;
        int ans=0;
        int cur=0;
        for(auto& p:pool)
        {
            cur+=p.second;
            ans=max(ans,cur);
        }
        return ans;
    }
};