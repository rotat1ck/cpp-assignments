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

    int min = arr[SIZE-1];
    int index = -1;

    for (int i = SIZE-1; i >= 0; --i) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }

    cout << "Наименғшее число массива: " << min << endl;
    cout << "Индекс числа: " << index;
}