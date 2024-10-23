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

    cout << "Просто введеный вами массив: ";
    
    for (int i =0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
}