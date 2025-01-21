#include <chrono>
#include <iostream>

class Timer {
private:
    static std::chrono::high_resolution_clock::time_point start;
    static std::chrono::high_resolution_clock::time_point stop;
public:
    static void startTimer() {
        start = std::chrono::high_resolution_clock::now();
    }

    static void stopTimer() {
        stop = std::chrono::high_resolution_clock::now();
        double elapsed = elapsedSeconds();
        std::cout << "Elapsed time: " << static_cast<int>(elapsed * 1000) / 1000.0 << "s" << std::endl;
    }

    static double elapsedSeconds() {
        return std::chrono::duration<double>(stop - start).count();
    }
};

std::chrono::high_resolution_clock::time_point Timer::start;
std::chrono::high_resolution_clock::time_point Timer::stop;