#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <conio.h>

using namespace std;

void one() {
    cout << "Результат: " << endl;
    for (int i = 1; i <= 5; ++i) {
        cout << i << "\t" << pow(i, 2) << endl;
    }
}

void two(int n) {
    double result = 0;
    double sinsum = 0;

    for (int i = 1; i <= n; ++i) {
        sinsum += sin(i * M_PI / 180);
        result += 1 / sinsum;
    }
    cout << "Результат: " << result << endl;
}

void three(double h, double a, double b) {
    cout << setprecision(3) << "Результат: " << endl;
    for (double x = a; x <= b; x += h) {
        double ln_x = log(x);
        double cot_ln_x = 1 / tan(ln_x);
        double result = cot_ln_x * cot_ln_x;
        cout << result << "\n";
    }
}

// высота и ширина ромба должны быть одинаковыми, иначе это уже будет не ромб
// поэтому принимаю только один параметр размера
void four(int size) {
    if (size % 2 == 0) {
        cout << "Неверный ввод";
        return;
    }

    vector<char> allowedKeys= {'1', '2', '3'};
    cout << "Выберете символ: \n" << "1. *\n2. +\n3. #" << endl;
    char ch;
    char symbol;
    while(true) {
        if (_kbhit()) {
            ch = _getch();
            if (find(allowedKeys.begin(), allowedKeys.end(), ch) != allowedKeys.end()) {
                switch(ch) {
                    case '1': {
                        symbol = '*';
                        break;
                    } case '2': {
                        symbol = '+';
                        break;
                    } case '3': {
                        symbol = '#';
                        break;
                    }
                }
                break;
            }
        }
    }


    int gapsize = (size - 1) / 2;
    string gap(gapsize, ' ');

    cout << gap << symbol << gap << endl;

    for (int i = 1; i <= (size - 3) / 2; ++i) {
        gapsize = (size - 1) / 2 - i;
        string gap(gapsize, ' ');
        string inBetween(size - (gapsize * 2) - 2, ' ');
        cout << gap << symbol << inBetween << symbol << endl;
    }

    gap = string(size - 2, ' ');
    cout << symbol << gap << symbol << endl;

    for (int i = 1; i <= (size - 3) / 2; ++i) {
        gapsize = i;
        string gap(gapsize, ' ');
        string inBetween(size - (gapsize * 2) - 2, ' ');
        cout << gap << symbol << inBetween << symbol << endl;
    }

    gap = string((size - 1) / 2, ' ');
    cout << gap << symbol << gap << endl; 
}

void five(int size) {
    vector<int> nums;
    
    std::srand(std::time(0));
    
    for (int i = 0; i < size; i++) {
        nums.push_back(std::rand() % 20001 - 10000);
    }

    cout << "Результат: ";
    for_each(nums.begin(), nums.end(), [](int num) {
        if (num % 2 != 0) {
            cout << num << " ";
        }
    });
    cout << endl;
}

void 🥨() {
    cout << "ESC - Закрыть программу" << endl;
    vector<char> allowedKeys= {'1', '2', '3', '4', '5'};
    cout << "Выберете задание: \n" << "1. Таблица квадратов\n2. Математика 1 класс\n3. Таблица очень страшной функции\n4. Ромб\n5. Случайные нечетные числа" << endl;
    char ch;
    while(true) {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 27) {
                exit(0);
            } else if (find(allowedKeys.begin(), allowedKeys.end(), ch) != allowedKeys.end()) {
                switch(ch) {
                    case '1': {
                        system("cls");
                        one();
                        break;
                    } case '2': {
                        system("cls");
                        int n;
                        cout << "Введите число N: ";
                        cin >> n;

                        two(n);
                        break;
                    } case '3': {
                        system("cls");
                        cout << "Введите шаг табулирования: ";
                        double h;
                        cin >> h;

                        cout << "Введите начало интервала: ";
                        double a;
                        cin >> a;

                        cout << "Введите конец интервала: ";
                        double b;
                        cin >> b;
                        three(h, a, b);
                        break;
                    } case '4': {
                        system("cls");
                        cout << "Введите размер ромба: ";
                        int size;
                        cin >> size;
                        four(size);
                        break;
                    } case '5': {
                        system("cls");
                        cout << "Введите размер массива: ";
                        int size;
                        cin >> size;
                        five(size);
                        break;
                    }
                }
                🥨();
            }
            system("cls");
            cout << "Некорректный ввод\n";
            🥨();
        }
    }
}


int main() {
    system("chcp 65001");
    system("cls");
    🥨();

    // 🥨
}