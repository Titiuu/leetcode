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

using namespace std;

class ParkingSystem {
private:
    vector<int> park;
    int bigsize, mediumsize, smallsize;
public:
    ParkingSystem(int big, int medium, int small) {
        park = vector<int>(3, 0);
        bigsize = big;
        mediumsize = medium;
        smallsize = small;
    }
    
    bool addCar(int carType) {
        switch (carType)
        {
        case 3:
            if (park[0] == smallsize)
                return false;
            else {
                park[0]++;
                return true;
            }
            break;
        case 2:
            if (park[1] == mediumsize)
                return false;
            else {
                park[1]++;
                return true;
            }
            break;
        case 1:
            if (park[2] == bigsize)
                return false;
            else {
                park[2]++;
                return true;
            }
            break;
        default:
            return false;
            break;
        }
    }
};