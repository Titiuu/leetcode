#include "head.h"

class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        if (sx == tx && sy == ty)
            return true;
        if (sx > tx || sy > ty)
            return false;
        while (tx != ty) {
            if (tx > ty) {
                if (sy==ty && sx > sy && (tx - sx) % ty == 0)
                    return true;
                if (tx % ty == 0)
                    tx = ty;
                else
                    tx %= ty;
            }
            else {
                if (sx==tx && sx < sy && (ty - sy) % tx == 0)
                    return true;
                if (ty % tx == 0)
                    ty = tx;
                else
                    ty %= tx;
            }
            if (sx == tx && sy == ty)
                return true;
            if (sx > tx || sy > ty)
                return false;
        }
        return false;
    }
};

int main() {
    Solution S;
    cout << (S.reachingPoints(1, 8, 4, 15) == 0 ? "false" : "true");
    return 0;
}