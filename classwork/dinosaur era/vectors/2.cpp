#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int size, sum = 0;
    vector<int> vec;

    cout << "Введите длину вектора: ";
    cin >> size;

    cout << "Введите числа: ";

    for (int i = 0; i < size; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    int max = vec.front();
    for (auto elem : vec) {
        if (elem > max) {
            max = elem;
        }
    }

    cout << "Наибольшее число вектора: " << max;
}