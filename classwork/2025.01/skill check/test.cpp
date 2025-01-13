#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string input1, input2;

    cout << "Введите 1 строку: ";
    getline(cin, input1);
    cout << "Введите 2 строку: ";
    getline(cin, input2);

    sort(input1.begin(), input1.end());
    sort(input2.begin(), input2.end());

    if (input1 == input2) {
        cout << "Анограм";
    } else {
        cout << "Не анограм";
    }
}
