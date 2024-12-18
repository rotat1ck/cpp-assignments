#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "C:\vscode\cpp-assignments\random\timer.hpp"

using namespace std;

struct gen {
    int _a;
    gen(int a) : _a(a) {};

    int operator()(int a) {
        _a = a;
        return _a;
    }
    int operator()() {
        return _a++;
    }
};

int main() {
    Timer timer;
    timer.startTimer();
    gen g(1);
    vector<int> vec(100000000);
    generate(vec.begin(), vec.end(), g);
    timer.stopTimer();
    
    // 🥨 
}
