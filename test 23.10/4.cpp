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

    cout << "Четные числа: ";
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] % 2 == 0) {
            cout << arr[i] << " ";
        }
    }
}