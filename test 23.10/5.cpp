#include <iostream>

using namespace std;

int main() {
    int SIZE, x;

    cout << "Введите размер массива: ";
    cin >> SIZE;

    int arr[SIZE];

    cout << "Введите числа в массив: ";
    
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }

    cout << "Введите число для поиска: ";
    cin >> x;

    int counter = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == x) {
            counter++;
        }
    }

    cout << "Кол-во чисел равных " << x << " : " << counter;
}