#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

const double Pi = asin(1.0), g = 9.81;

double one(double &x, double &y) {
    x = (x / 180) * Pi;
    y = (y / 180) * Pi;
    return pow(1 - tan(x), (cos(x) / sin(x))) + cos(x-y);
}

double two(double &v, double &t) {
    const double a = asin(g * t / (2 * v));
    if (a >= -1 && a <= 1) {
        return a * (90 / Pi);
    } else {
        cout << "Error: invalid input" << endl;
        return -1;
    }
}

int three(int num) {
    vector<int> nums;
    while (num > 0) {
        nums.push_back(num % 10);
        num = num / 10;
    }
    return *max_element(nums.begin(), nums.end());
}

double four(vector<float> &arr, int &size) {
    double sum = accumulate(arr.begin(), arr.end(), 0);
    return sum / size;
}

int five(int &limit) {
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