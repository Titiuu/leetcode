#include "head.h"

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum = accumulate(distance.begin(), distance.end(), 0);
        if (start > destination) {
            int t = start;
            start = destination;
            destination = t;
        }
        int acc = 0;
        for (int i = start; i < destination; i++) {
            acc += distance[i];
        }
        return acc < sum - acc ? acc : sum - acc;
    }
};