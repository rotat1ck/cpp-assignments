#include <iostream>
#include <vector>

using namespace std;

vector<int> createVector(int size) 
{
    vector<int> vec;

    for (int i = 0; i < size; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    return vec;
}

int getSum(vector<int> vec, int size) 
{
    int sum = 0;
    
    for (auto elem: vec) {
        sum += elem;
    }

    return sum;
}

int main() 
{
    int size, sum = 0;
    cout << "Введите длину первого вектора: ";
    cin >> size;

    cout << "Введите числа: ";
    vector<int> v1 = createVector(size);
    sum += getSum(v1, size);

    cout << "Введите длину второго вектора: ";
    cin >> size;

    cout << "Введите числа: ";
    vector<int> v2 = createVector(size);
    sum += getSum(v2, size);

    cout << "Сумма чисел векторов: " << sum;

}