#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <regex>
#include <cmath>

using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int i = 0, j = 1, size = A.size();
        int up = 0, down = 0;
        for (; j < size; i++, j++) {
            if (A[i] < A[j])
                up++;
            if (A[i] > A[j])
                down++;
        }
        if (up>0 && down>0) return false;
        return true;
    }
};

int main() {
    Solution S;
    vector<int> A = {1,3,2};
    cout<<S.isMonotonic(A);
}