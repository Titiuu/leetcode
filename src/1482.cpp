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

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) { //m束花，每束k朵
        int n = bloomDay.size();
        if (n < m * k)  return -1;
        int low = 1, high = 1, days = 1;
        high = *max_element(bloomDay.begin(), bloomDay.end());
        low = *min_element(bloomDay.begin(), bloomDay.end());
        while (low < high) {
            days = (low + high) / 2;
            if (canMake(bloomDay, m, k, days))
                high = days;
            else
                low = days + 1;
        }
        return low;
    }
    bool canMake(vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0, flowers = 0;
        for (int i : bloomDay) {
            if (i <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else
                flowers = 0;
            if (bouquets == m)  return true;
        }
        return false;
    }
};