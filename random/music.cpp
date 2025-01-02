#include <iostream>
#include <windows.h>

using namespace std;

int main() {
    for (size_t i = 1; i < 100; ++i) {
        Beep(6000, 10);
    }
}