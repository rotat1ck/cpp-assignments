#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string input, oldWord, newWord;

    cout << "Введите строку: ";
    getline(cin, input);

    cout << "Введите слово для замены: ";
    getline(cin, oldWord);
    
    cout << "Введите новое слово: ";
    getline(cin, newWord);
    
    size_t pos = 0;

    while ((pos = input.find(oldWord, pos)) != string::npos) {
        input.replace(pos, oldWord.length(), newWord);
    }
    cout << "Результат: " << input;
    return 0;
}