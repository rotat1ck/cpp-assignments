#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <unordered_map>

using namespace std;

unordered_map<char, string> morseCodeMap = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."},
    {'8', "---.."}, {'9', "----."},
    {' ', "/"}
};

void one();
void two();
void three();
void four();
void five();
void six();
void seven();

int start() {
    cout << "Выберите номер задания от 1 до 7: ";
    while (true) {
        if (kbhit()) {
            switch(getch()) {
                case 49:
                    one();
                    break;
                case 50:
                    two();
                    break;
                case 51:
                    three();
                    break;
            }
        }
    }
}


int main() {
    system("chcp 65001");
    system("cls");
    start();

}

void one() {
    int a,b;
    system("cls");
    cout << "Введите два числа: ";
    cin >> a >> b;
    
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }

    cout << "Наибольший общий делитель: " << a << endl;
    start();
}

void two() {
    system("cls");
    vector<int> nums; 
    cout << "Введите числа через ENTER в массив (ESC - закончить ввод): " << endl;
    char ch;
    bool noesc = true;
    int converted = 0;

    while (noesc) {
        if (_kbhit()) {
            ch = _getch();

            if (ch == 27) {
                noesc = false;
                break;
            } else if (ch == '\r') {
                if (converted != 0) {
                    nums.push_back(converted);
                    cout << endl;
                    converted = 0;
                }
            } else if (ch >= '0' && ch <= '9') {
                converted = converted * 10 + (ch - '0');
                cout << ch;
            }
        }
    }

    cout << "\nВведенный массив: ";
    for (auto num : nums) {
        cout << num << " ";
    }

    cout << "\nПеревернутый массив: ";
    for(int i = nums.size()-1; i >= 0; --i) {
        cout << nums[i] << " ";
    }
    
    cout << endl;
    start();
}

void three() {
    system("cls");
    cout << "Введите текст для преобразования в морзянку (ENTER - закончить ввод): " << endl;
    char ch;
    bool noesc = true;
    string inputText;
    
    while (noesc) {
        if (_kbhit()) {
            ch = _getch();

            if (ch == '\r') {
                cout << endl;
                break;
            } else {
                inputText += toupper(ch);
                cout << ch;
            }
        }
    }


    cout << "\nМорзянка: ";
    for (char c : inputText) {
        if (morseCodeMap.find(c) != morseCodeMap.end()) {
            cout << morseCodeMap[c] << " "; 
        } else {
            cout << "? "; 
        }
    }
    
    cout << endl;
    start();
}