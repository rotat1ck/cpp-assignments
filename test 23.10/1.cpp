#include <iostream>

using namespace std;

int main() {
    int SIZE;

    cout << "Введите размер массива: ";
    cin >> SIZE;

    int arr[SIZE];

    cout << "Введите числа в массив: ";

    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }

    int counter = 0;

    for (int i = 0; i < SIZE; ++i) {
        counter += arr[i];
    }

    cout << "Сумма чисел массива: " << counter;
}