#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;

    swap(&a, &b);
    
    std::cout << "Первое число: " << a << endl;
    std::cout << "Второе число: " << b;

    return 0;
}