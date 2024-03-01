#include "head.h"

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int i = 0; i < n; i++) {
            if (gas[i] < cost[i])
                continue;
            int sum = 0, j = i;
            for (; j < i + n; j++) {
                sum += gas[j % n] - cost[j % n];
                if (sum < 0) {
                    break;
                }
            }
            if (j == i + n)
                return i;
            else
                i = j;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> gas = { 1,2,3,4,5 }, cost = { 3,4,5,1,2 };
    cout << s.canCompleteCircuit(gas, cost);
}