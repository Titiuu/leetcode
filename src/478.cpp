#include "head.h"

class Solution {
public:
    double r, x, y;
    Solution(double radius, double x_center, double y_center):r(radius), x(x_center), y(y_center){}
    
    vector<double> randPoint() {
        random_device gen;
        uniform_real_distribution<double> a(0, r * r), b(0, 2 * M_PI);
        double len = sqrt(a(gen)), ang = b(gen);
        return { x + len * cos(ang), y + len * sin(ang) };
    }
};