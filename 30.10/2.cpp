#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void plusarr(int *arr, int size, int increment) 
{
    for (int i = 0; i < size; ++i) {
        arr[i] += increment;
    }
}

int main() 
{   
    int size = 5;
    int arr[size];
    for (int i = 0; i < size; ++i) {
        arr[i] = i;
    }
    int increment = 3;

    
    plusarr(arr, size, increment);

    cout << "Элементы массива: ";

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}