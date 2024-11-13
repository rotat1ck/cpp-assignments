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
    {' ', "|"}
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
                case 27:
                    exit(0);
                    return 0;
                case 49:
                    one();
                    break;
                case 50:
                    two();
                    break;
                case 51:
                    three();
                    break;
                case 52:
                    four();
                    break;
                case 53:
                    five();
                    break;
                case 54:
                    six();
                    break;
                case 55:
                    seven();
                    break;
            }
        }
    }
}


int main() {
    system("chcp 65001");
    system("cls");
    cout << "ESC - Закрыть программу" << endl;
    start();

}

void one() {
    int a,b;
    system("cls");
    cout << "Введите два числа: ";
    cin >> a >> b;

    a = abs(a), b = abs(b);

    if (a != 0 && b != 0) {
        while (a != b) {
            if (a > b) {
                a = a - b;
            } else {
                b = b - a;
            }
        }
    } else {
        
        if (a == 0) {
            a = b;
        }
    }
    cout << "Наибольший общий делитель: " << a << endl;
        start();
}

void two() {
    system("cls");
    vector<int> nums; 
    cout << "Введите числа в массив через пробел (ESC, ENTER - закончить ввод): ";
    char ch;
    bool noesc = true;
    int converted = 0;

    while (noesc) {
        if (_kbhit()) {
            ch = _getch();

            if (ch == 27 || ch == '\r') {
                noesc = false;
                break;
            } else if (ch == 32) {
                if (converted != 0) {
                    nums.push_back(converted);
                    cout << " ";
                    converted = 0;
                }
            } else if (ch >= '0' && ch <= '9') {
                converted = converted * 10 + (ch - '0');
                cout << ch;
            }
        }
    }

    nums.push_back(converted);
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
    cout << "Введите текст на английском для преобразования в азбуку морзе: " << endl;
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

    cout << "\nКод морзе: ";
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

void four() {
    system("cls");
    cout << "Введите строку для сжатия: ";
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
                inputText += tolower(ch);
                cout << ch;
            }
        }
    }

    cout << "Результат сжатия:";

    char lastChar = inputText[0];
    int repeatCounter = 1;
    cout << lastChar;

    for (int i = 1; i < inputText.size(); ++i) {
        if (lastChar == inputText[i]) {
            repeatCounter++;
        } else if (repeatCounter > 1){
            cout << repeatCounter << inputText[i];
            lastChar = inputText[i];
            repeatCounter = 1;
        } else {
            cout << inputText[i];
            lastChar = inputText[i];
            repeatCounter = 1;
        } 
    }

    if (repeatCounter > 1) {
        cout << repeatCounter;
    }
    cout << endl;
    start();
}

void five() {
    system("cls");
    int m, n;
    cout << "Введите размер прямоугольника: ";
    cin >> m >> n;
    cout << endl;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << '*';
        }
        cout << endl;
    }

    cout << endl;
    start();
}

void six() {
    system("cls");
    cout << "Все четырехзначные числа сумма цифр которых равна 15: " << endl;

    for (int i = 1000; i <= 9999; ++i) {
        int sum = 0;
        int num = i;
        while (num!=0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum == 15) {
            cout << i << " ";
        }
    }

    cout << endl;
    start();
}

void seven() {
    system("cls");
    vector<int> grades;
    cout << "Введите оценки через пробел (ESC, ENTER - закончить ввод): ";
    char ch;
    bool noesc = true;
    
    while (noesc) {
        if (_kbhit()) {
            ch = _getch();

            if (ch == 27 || ch == '\r') {
                noesc = false;
                break;
            } else if (ch == 32) {
                cout << " ";
            } else if (ch >= '2' && ch <= '5') {
                grades.push_back(ch - '0');
                cout << ch;
            }
        }
    }

    double avg;
    int totalSolved = 0, sum = 0;
    int numOfProblems = grades.size();
    
    for (auto grade : grades) {
        if (grade > 2) {
            totalSolved++;
        } 
        sum += grade;
    }

    if (totalSolved >= numOfProblems / 2) {
        avg = sum / static_cast<double> (numOfProblems);
        cout << "\nКонтрольная сдана, финальная оценка: " << avg;
    } else {
        cout << "\nКонтрольная не сдана, финальная оценка: 2";
    }

    cout << endl;
    start();
}
