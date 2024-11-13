#include <iostream>
#include <cstdlib>
#include <ctime>

int insertSort(int arr[], int SIZE) 
{
    for(int i = 1; i < SIZE; i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]) {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
    
    return *arr;
}

int main() 
{
    const int SIZE = 10;
    int arr[SIZE];
    
    std::srand(std::time(0));
    
    for (int i = 0; i < SIZE; i++) {
        arr[i] = std::rand() % 201 - 100;
    }

    *arr = insertSort(arr, SIZE);

    std::cout << "Отсортированный список: ";

    for (int i = 0; i < SIZE; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
}