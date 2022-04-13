#include "head.h"

class RandomizedSet {
public:
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (indices.find(val) != indices.end()) {
            return false;
        }
        indices[val] = nums.size();
        nums.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (indices.find(val) == indices.end()) {
            return false;
        }
        int index = indices[val];
        int last = nums.back();
        nums[index] = last;
        indices[last] = index;
        nums.pop_back();
        indices.erase(val);
        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    }
private:
    vector<int> nums;
    unordered_map<int, int> indices;
};

class RandomizedSet {
public:
    unordered_set<int> set;
    random_device rd;
    RandomizedSet() {}

    bool insert(int val) {
        return set.insert(val).second;
    }

    bool remove(int val) {
        return set.erase(val);
    }

    int getRandom() {
        int k = (int)(rd() % set.size());
        int i = 0;
        for (int a : set) {
            if (i == k)
                return a;
            i++;
        }
        return 0;
    }
};