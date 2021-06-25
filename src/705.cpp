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

class MyHashSet {
public:
    vector<bool> nodes;

    MyHashSet() {
        nodes = vector<bool>(1000001, false);
    }

    void add(int key) {
        nodes[key] = true;
    }
    
    void remove(int key) {
        nodes[key] = false;
    }
    
    bool contains(int key) {
        return nodes[key];
    }
};