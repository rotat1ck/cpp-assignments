#include <chrono>
#include <iostream>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point stop;
public:
    void startTimer() {
        start = std::chrono::high_resolution_clock::now();
    }

    void stopTimer() {
        stop = std::chrono::high_resolution_clock::now();
        double elapsed = elapsedSeconds();
        std::cout << "Elapsed time: " << static_cast<int>(elapsed * 1000) / 1000.0 << "s" << std::endl;
    }

    double elapsedSeconds() {
        return std::chrono::duration<double>(stop - start).count();
    }
};