#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <conio.h>

using namespace std;

void start();

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

void one(const vector<int> &nums) {
    system("cls");

    cout << "Результат: " << count_if(nums.begin(), nums.end(), [](int a) { return a % 2 == 0; }) << endl;
    start();
}

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

void six(const vector<int> &nums, int n) {
    system("cls");

    cout << "Результат: " << count_if(nums.begin(), nums.end(), [=](int a) { return a > n; }) << endl;
    start();
}

void start() {
    cout << "Выберите номер задания от 1 до 6: ";
    while (true) {
        if (kbhit()) {
            switch (getch()) {
                case 27:
                    exit(0);
                case 49: {
                    vector<int> nums = createVector();
                    one(nums);
                    break;
                }
                case 50: {
                    vector<int> nums = createVector();
                    int n;
                    cout << "\nВведите число N (размер шага): ";
                    cin >> n;
                    two(nums, n);
                    break;
                }
                case 51: {
                    vector<int> nums = createVector();
                    three(nums);
                    break;
                }
                case 52: {
                    vector<int> nums = createVector();
                    four(nums);
                    break;
                }
                case 53: {
                    vector<int> nums = createVector();
                    five(nums);
                    break;
                }
                case 54: {
                    vector<int> nums = createVector();
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

int main() {
    system("chcp 65001");
    system("cls");
    cout << "ESC - Закрыть программу" << endl;
    start();
}