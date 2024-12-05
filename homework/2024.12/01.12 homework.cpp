#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <conio.h>

using namespace std;

void start();

// функция создания вектора для всех заданий
vector<int> createVector() {
    system("cls");

    vector<int> nums;
    cout << "Введите числа через пробел (ESC, ENTER - закончить ввод): ";
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
                nums.push_back(converted);
                cout << " ";
                converted = 0;
                
            } else if (ch >= '0' && ch <= '9') {
                converted = converted * 10 + (ch - '0');
                cout << ch;
            }
        }
    }

    if (converted != 0) {
        nums.push_back(converted);
    }

    return nums;
}

// 1 🥨
void one(const vector<int> &nums) {
    system("cls");

    cout << "Результат: " << count_if(nums.begin(), nums.end(), [](int a) { return a % 2 == 0; }) << endl;
    start();
}

// 2 🥨
void two(const vector<int> &nums, int n) {
    system("cls");

    vector<double> res;
    for (int i = 0; i <= n; ++i) {
        double sum = accumulate(nums.begin() + i, nums.begin() + (i + n), 0.0);
        res.push_back(sum / n);
    }

    cout << "Результат: ";
    for (auto num : res) {
        cout << num << " ";
    }
    cout << endl;
    start();
}

// 3 🥨
void three(const vector<int> &nums) {
    system("cls");

    double avg = accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
    cout << "Результат: ";
    for (auto num : nums) {
        cout << num - avg << " ";
    }
    cout << endl;
    start();
}

// 4 🥨
void four(const vector<int> &nums) {
    system("cls");

    vector<int> predResult;
    copy_if(nums.begin(), nums.end(), back_inserter(predResult), [](int x) { return x % 13 == 0 && x != 0; });
    if (!predResult.empty()) {
        cout << "Результат: " << *max_element(predResult.begin(), predResult.end()) << endl;
    } else {
        cout << "Результат: " << -1 << endl;
    }
    start();
}

// 5 🥨
void five(const vector<int> &nums) {
    system ("cls");

    vector<int> sortedNums = nums;
    sort(sortedNums.begin(), sortedNums.end());
    int size = sortedNums.size();
    if (size % 2 != 0) {
        cout << "Результат: " << sortedNums[size / 2] << endl;
    } else {
        cout << "Результат: " << (sortedNums[size / 2 - 1] + sortedNums[size / 2]) / 2.0 << endl;
    }
    start();
}

// 6 🥨
void six(const vector<int> &nums, int n) {
    system("cls");

    cout << "Результат: " << count_if(nums.begin(), nums.end(), [=](int a) { return a > n; }) << endl;
    start();
}

// стартовая функция выбора заданий
void start() {
    vector<char> allowedKeys= {'1', '2', '3', '4', '5', '6'};
    cout << "Выберите номер задания от 1 до 6: ";
    while (true) {
        if (_kbhit()) {
            char key = _getch();
            if (key == 27) {
                exit(0);
            } else if (find(allowedKeys.begin(), allowedKeys.end(), key) != allowedKeys.end()){
                vector<int> nums = createVector();
                switch(key) {
                    case '1': {
                        one(nums);
                        break;
                    } case '2': {
                        int n;
                        cout << "\nВведите число N (размер шага): ";
                        cin >> n;
                        two(nums, n);
                        break;
                    } case '3': {
                        three(nums);
                        break;
                    } case '4': {
                        four(nums);
                        break;
                    } case '5': {
                        five(nums);
                        break;
                    } case '6': {
                        int n;
                        cout << "\nВведите число N: ";
                        cin >> n;
                        six(nums, n);
                        break;
                    }
                }
            }
        }
    }
}

// включение utf-8 и информирование пользователя
int main() {
    system("chcp 65001");
    system("cls");
    cout << "ESC - Закрыть программу" << endl;
    start();

    // 🥨
}