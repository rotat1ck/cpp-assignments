#include <iostream>

using namespace std;

void insertData(int* &arr, int SIZE) 
{
    for (int i = 0; i < SIZE; ++i) {
        cin >> arr[i];
    }
}

double average(int* arr, int SIZE) 
{
    int sum;

    for (int i = 0; i < SIZE; ++i) {
        sum += arr[i];
    }

    return (sum / static_cast<double>(SIZE));
}

int bestStudents(int* arr, int SIZE) {
    double avg = average(arr, SIZE);
    int counter = 0;

    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] > avg) {
            counter++;
        }
    }

    return counter;
}

int main() 
{
    int SIZE;

    cout << "Введите размер массива: ";
    cin >> SIZE;

    int* arr = new int[SIZE];

    cout << "Введите числа в массив: ";

    insertData(arr, SIZE);

    cout << "Оценки студентов: ";
    for (int i = 0; i < SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << "\nСредняя оценка: " << average(arr, SIZE) << endl;
    cout << "Кол-во студентов с оценкой выше среднего: " << bestStudents(arr, SIZE);

    delete[] arr;
    return 0;
}