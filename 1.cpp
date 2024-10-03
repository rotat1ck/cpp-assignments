#include <iostream>
#include <string>

using namespace std;

int main() {
    system("chcp 65001");
    system("cls");

    string input;
    char chr;
    cout << "Введите строку: ";
    getline(cin, input);
    cout << "Введите символ для удаления: ";
    cin >> chr;
    for (size_t i =0; i < input.size(); i++) {
        if (input[i] == chr) {
            input.erase(i, 1);
            i--;
        }
    }
    cout << input;
    return 0;
    

}