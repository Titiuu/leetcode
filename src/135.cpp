#include "head.h"

class Solution {
private:
    void increase(vector<int>& ratings, vector<int>& candies, int index) {
        int i = index, j = index;
        if (i > 0 && ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i])
            candies[i - 1] = candies[i] + 1;
        if (j < candies.size() - 1 && ratings[j + 1] > ratings[j] && candies[j + 1] <= candies[j])
            candies[j + 1] = candies[j] + 1;
        // if (i == 0 || j == candies.size() || ratings[i - 1] <= ratings[i] || ratings[j + 1] <= ratings[j])
        //     break;
    }
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> index(n, 0);
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(),
            [&ratings](size_t index_1, size_t index_2) {
                return ratings[index_1] < ratings[index_2];
            });
        vector<int> candies(n, 1);
        for (auto& x : index) {
            increase(ratings, candies, x);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

int main() {
    Solution s;
    vector<int> ratings = { 1,3,2,2,1 };
    cout << s.candy(ratings);
}