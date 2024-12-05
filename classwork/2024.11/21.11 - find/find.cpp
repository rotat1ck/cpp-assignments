#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> number{10, 23, 174, 45, 67, 34};
    auto max_number = find(number.begin(), number.end(), 34);
    
    if (max_number == number.end()) {
        cout << "Такого нет";
    } else {
        cout << "Позиция: " << distance(number.begin(), max_number);
    }
    return 0;

    // 🥨
}