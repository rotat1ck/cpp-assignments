#include <iostream>

using namespace std;

int main()
{    
    system("chcp 65001");
    system("cls");

    int n;
    int result;
    cout << "Введите число: ";
    cin >> n;
    int check = n;

    // я использовал тот же принцип что и в первой задача
    // так что для него не нужен цикл for
    for (int i = 0; n > 0; i++) {
        result = result * 10 + n % 10;
        n /= 10;
    }

    if (result == check) {
        cout << "Число является палиндромом";
    } else {
        cout << "Число не является палиндромом";
    }

    return 0;
}
