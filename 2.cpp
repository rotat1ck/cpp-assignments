#include <iostream>

using namespace std;

int main() 
{
    system("chcp 65001");
    system("cls");

    cout << "Введите числа (отрицательное для окончания ввода): ";
    int n, result = 0, i = 0;

    do {
        cin >> n;
        if (n > 0) {
            result += n;
            i++;
        }
    } while (n > 0);

    cout << "\nРезультат: " << result / i;

    return 0;
}