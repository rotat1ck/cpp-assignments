#include <iostream>
#include <string>

using namespace std;

int main() 
{
    system("chcp 65001");
    system("cls");

    string input;
    int c =1;

    cout << "Введите строку: ";
    getline(cin, input);

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] == ' ') {
            c++;
        }
    }
    cout << "Количество слов: " << c;
    return 0;
}