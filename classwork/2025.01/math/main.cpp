#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

double one(double x, double y) {
    const double pi = M_PI;
    x = (x / 180) * pi;
    y = (y / 180) * pi;
    return pow(1 - tan(x), (cos(x) / sin(x))) + cos(x-y);
}

double two(double v, double t) {
    return asin(10 * t / 2 * v);
}

int three(int num) {
    vector<int> nums;
    while (num > 0) {
        nums.push_back(num % 10);
        num = num % 10;
    }
    return *max_element(nums.begin(), nums.end());
}

double four(vector<float> &arr, int size) {
    double sum = accumulate(arr.begin(), arr.end(), 0);
    return sum / size;
}

int five(int limit) {
    int result = 0;
    int ptr = 0;
    while (ptr <= limit) {
        ptr++;
        if (ptr % 5 == 0) {
            result += ptr;
        }
    }
    return result;
}