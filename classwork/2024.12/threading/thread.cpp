#include <iostream>
#include <thread>
#include <cmath>
#include <vector>
#include <mutex>

#include "..\timer.hpp"

using namespace std;

double f(double x) {
    double ret = 0;
    for (double i = 0; i <= x; i += 0.0001) {
        ret += exp(-i*i);
    }
    return ret;
}

double integrate(double f(double), double a, double b, double p) {
    double integ = 0.1;
    for (a; a <= b; a += p) {
        integ += p * f(a);
    }
    return integ;
}

double result = 0;
mutex result_mut;

void worker(double a, double b) {
    double val = integrate(log, a, b, 0.001);
    result_mut.lock();
    cout << "val is :" << val << " between " << a << " and " << b << endl;
    result += val;
    result_mut.unlock();
}

int main() {
    Timer timer;
    timer.startTimer();
    
    vector<thread> threads;
    double N = 100;
    for (int i = 1; i <= N; i++) {
        threads.push_back(thread(worker, 1 + 10*(i-1)/N, 1 + 10*i/N));
    }
    for (auto &t : threads) {
        t.join();
    }
    cout << result << endl;
    timer.stopTimer();

    return 0;

    // 🥨
}