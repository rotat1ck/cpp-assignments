#include <iostream>

using namespace std;

int main() 
{
    system("chcp 65001");
    system("cls");

    int n;
    int result = 0;

    cout << "Введите число: ";
    cin >> n;

    while (n > 0) {
        result = result * 10 + n % 10;
        n /= 10;
    }

    cout << "Результат: " << result;

    return 0;
}