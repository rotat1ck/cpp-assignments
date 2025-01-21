#include <iostream>
#include "C:\vscode\cpp-assignments\random\timer.hpp"

using namespace std;

class users {
public:
    static int userCount;

    static int getUserCount() {
        return userCount;
    }
    static void changeUserCount(int n) {
        userCount = n;
    }
};

int users::userCount = 5;

int main() {
    Timer::startTimer();

    cout << users::getUserCount() << endl;

    users::changeUserCount(15);

    cout << users::getUserCount() << endl;

    Timer::stopTimer();
}