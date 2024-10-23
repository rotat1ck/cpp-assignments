#include <iostream>

using namespace std;

int main() {
    int SIZE, sum = 0;

    cout << "Введите размер массива: ";
    cin >> SIZE;

    int arr[SIZE];

    cout << "Введите числа в массив: ";
    
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    double avg = sum / static_cast<double>(SIZE);
    int counter = 0;

    for (int i =0; i < SIZE; ++i) {
        if (arr[i] >= avg) {
            counter++;
        }
    }

    cout << "Среднее арифметическое: " << avg << endl;
    cout << "Кол-во чисел больше среднего арифметического: " << counter;
}